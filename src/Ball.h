#pragma once

#include <SFML/System/Vector2.hpp>

class Map;

namespace sf {
class RenderTarget;
} // namespace sf

class Ball
{
public:
    explicit Ball(const sf::Vector2f& position);

    void Render(sf::RenderTarget& target) const;

    void Update(float dt, Map& map);

private:
    static constexpr float RADIUS = 0.05f;

    sf::Vector2f m_position;
    sf::Vector2f m_direction { 0.f, 1.f };
    float m_speed = 1.f;
};
