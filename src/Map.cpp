#include "Map.h"

#include "Physics/Bounce.h"
#include "Physics/Geometry.h"

#include <fstream>
#include <string>

void Map::Load(const std::filesystem::path& path)
{
    m_breakables.clear();

    std::fstream stream { path, std::ios_base::in };

    std::string line;
    for (size_t y = 0u; std::getline(stream, line); ++y)
    {
        for (size_t x = 0u, end = line.size(); x < end; ++x)
        {
            if (line[x] != ' ')
            {
                m_breakables.emplace_back(x, y);
            }
        }
    }
}

void Map::Render(sf::RenderTarget& target) const
{
    for (const auto& breakable : m_breakables)
    {
        breakable.Render(target);
    }
}

BounceResult Map::Bounce(Sphere sphere, sf::Vector2f speed)
{
    while (true)
    {
        const auto result = BounceOnce(sphere, speed);
        if (result.rate > 1.f)
        {
            return result;
        }

        const auto remaining_length = Length(speed) * (1.f - result.rate);
        if (IsEpsilon(remaining_length))
        {
            return result;
        }

        sphere.center = sphere.center + speed * result.rate;
        speed         = Scale(result.direction, remaining_length);
    }
}

BounceResult Map::BounceOnce(const Sphere& sphere, const sf::Vector2f& speed)
{
    BounceResult result { sphere.center + speed, speed };

    BounceOnWalls(result, sphere, speed);
    BounceOnSlider(result, sphere, speed);
    BounceOnBreakables(result, sphere, speed);

    return result;
}

bool Map::BounceOnWalls(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed)
{
    const sf::Vector2f top_left { -1.f, 1.f };
    const sf::Vector2f top_right { +1.f, 1.f };
    const sf::Vector2f bottom_left { -1.f, -1.f };
    const sf::Vector2f bottom_right { +1.f, -1.f };

    auto bounced = false;
    bounced |= ::Bounce(result, sphere, speed, Segment { top_left, top_right });
    bounced |= ::Bounce(result, sphere, speed, Segment { top_left, bottom_left });
    bounced |= ::Bounce(result, sphere, speed, Segment { top_right, bottom_right });
    return bounced;
}

bool Map::BounceOnSlider(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed)
{
    if (::Bounce(result, sphere, speed, m_slider.GetBoundingBox()))
    {
        const auto impact = sphere.center + speed * result.rate;

        result.direction   = m_slider.ComputeTrajectory(result.direction);
        result.destination = impact + Scale(result.direction, (1.f - result.rate) * Length(speed));

        return true;
    }

    return false;
}

bool Map::BounceOnBreakables(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed)
{
    const auto end = m_breakables.end();
    auto to_break  = end;

    for (auto it = m_breakables.begin(); it != end; ++it)
    {
        if (::Bounce(result, sphere, speed, it->GetBoundingBox()))
        {
            to_break = it;
        }
    }

    if (to_break != end)
    {
        m_breakables.erase(to_break);
        return true;
    }

    return false;
}
