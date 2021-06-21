#pragma once

#include <SFML/System/Vector2.hpp>

namespace sf {
class RenderTarget;
} // namespace sf

class Breakable
{
public:
    Breakable(size_t x, size_t y);

    void Render(sf::RenderTarget& target) const;

private:
    static inline const sf::Vector2f SIZE { 0.2f, 0.12f };
    sf::Vector2f m_position;
};
