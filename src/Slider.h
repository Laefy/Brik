#pragma once

#include <SFML/System/Vector2.hpp>

namespace sf {
class RenderTarget;
} // namespace sf

class Slider
{
public:
    void Render(sf::RenderTarget& target) const;

    void SetAcceleration(float acceleration);
    void Update(float dt);

private:
    const sf::Vector2f m_size { 0.3f, 0.05f };
    float m_position     = 0.f;
    float m_speed        = 0.f;
    float m_acceleration = 0.f;
};
