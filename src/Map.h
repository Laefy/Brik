#pragma once

#include "Breakable.h"
#include "Slider.h"

#include <filesystem>
#include <vector>

struct BounceResult;
struct Sphere;

namespace sf {
class RenderTarget;
}

class Map
{
public:
    void Load(const std::filesystem::path& path);

    void Render(sf::RenderTarget& target) const;

    BounceResult Bounce(Sphere sphere, sf::Vector2f speed);

    Slider& GetSlider() { return m_slider; }

private:
    BounceResult BounceOnce(const Sphere& sphere, const sf::Vector2f& speed);

    bool BounceOnWalls(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed);
    bool BounceOnSlider(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed);
    bool BounceOnBreakables(BounceResult& result, const Sphere& sphere, const sf::Vector2f& speed);

    Slider m_slider;
    std::vector<Breakable> m_breakables;
};