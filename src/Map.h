#pragma once

#include "Breakable.h"

#include <filesystem>
#include <vector>

namespace sf {
class RenderTarget;
}

class Map
{
public:
    void Load(const std::filesystem::path& path);

    void Render(sf::RenderTarget& target) const;

private:
    std::vector<Breakable> m_breakables;
};