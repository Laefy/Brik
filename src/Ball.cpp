#include "Ball.h"

#include "Map.h"
#include "Physics/Bounce.h"
#include "Physics/Geometry.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Ball::Ball(const sf::Vector2f& position) : m_position { position }
{
    m_position.y += RADIUS;
}

void Ball::Render(sf::RenderTarget& target) const
{
    sf::CircleShape shape { RADIUS };
    shape.setOrigin(sf::Vector2f { RADIUS, RADIUS });
    shape.setPosition(m_position);
    shape.setFillColor(sf::Color::Yellow);

    target.draw(shape);
}

void Ball::Update(float dt, Map& map)
{
    const auto speed = m_speed * dt;
    if (!IsEpsilon(speed))
    {
        const auto bounceResult = map.Bounce(Sphere { m_position, RADIUS }, speed * m_direction);
        m_direction             = Scale(bounceResult.direction, 1.f);
        m_position              = bounceResult.destination;
    }
}
