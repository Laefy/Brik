#include "Map.h"

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
