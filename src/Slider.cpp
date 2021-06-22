#include "Slider.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>

void Slider::Render(sf::RenderTarget& target) const
{
    sf::RectangleShape shape { SIZE };
    shape.setOrigin(sf::Vector2 { SIZE.x / 2.f, 0.f });
    shape.setPosition(sf::Vector2f { m_position, -1.f });
    shape.setFillColor(sf::Color::Green);

    target.draw(shape);
}

void Slider::SetAcceleration(float acceleration)
{
    constexpr auto RATIO = 1.2f;
    m_acceleration       = acceleration * RATIO;
}

void Slider::Update(float dt)
{
    constexpr auto FRICTION = 2.f;
    const auto friction     = -m_speed * FRICTION;

    constexpr auto MAX_SPEED = 0.7f;
    m_speed                  = std::clamp(m_speed + (m_acceleration + friction) * dt, -MAX_SPEED, +MAX_SPEED);

    constexpr auto BREAK_POINT = 0.03f;
    if (m_acceleration == 0.f && std::abs(m_speed) < BREAK_POINT)
    {
        m_speed = 0.f;
    }

    const auto max_position = 1.f - SIZE.x / 2.f;
    m_position              = std::clamp(m_position + m_speed * dt, -max_position, +max_position);

    m_bbox = ComputeBoundingBox(m_position);
}

sf::Vector2f Slider::ComputeTrajectory(const sf::Vector2f& original) const
{
    auto result = Scale(original, 1.f);

    constexpr auto COMMUNICATED_SPEED_RATE = 0.4f;
    result.x += m_speed / COMMUNICATED_SPEED_RATE;
    return result;
}

Rectangle Slider::ComputeBoundingBox(float position)
{
    return Rectangle { sf::Vector2f { position - SIZE.x / 2, -1.f + SIZE.y },
                       sf::Vector2f { position + SIZE.x / 2, -1.f } };
}