#pragma once

#include "Physics/Geometry.h"

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

    sf::Vector2f GetTopCenter() const { return sf::Vector2f { m_position, -1.f + SIZE.y }; }
    Rectangle GetBoundingBox() const { return m_bbox; }

    sf::Vector2f ComputeTrajectory(const sf::Vector2f& original) const;

private:
    static Rectangle ComputeBoundingBox(float position);

    static inline const sf::Vector2f SIZE { 0.3f, 0.05f };
    float m_position     = 0.f;
    float m_speed        = 0.f;
    float m_acceleration = 0.f;

    Rectangle m_bbox = ComputeBoundingBox(m_position);
};
