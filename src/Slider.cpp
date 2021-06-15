#include "Slider.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <algorithm>

void Slider::Render(sf::RenderTarget& target) const
{
    sf::RectangleShape shape { m_size };
    shape.setOrigin(sf::Vector2 { m_size.x / 2.f, 0.f });
    shape.setPosition(sf::Vector2f { m_position, -1.f });
    shape.setFillColor(sf::Color::Green);

    target.draw(shape);
}

void Slider::SetAcceleration(float acceleration)
{
    constexpr auto RATIO = 0.8f;
    m_acceleration       = acceleration * RATIO;
}

void Slider::Update(float dt)
{
    constexpr auto FRICTION = 2.f;
    const auto friction     = -m_speed * FRICTION;

    constexpr auto MAX_SPEED = 0.5f;
    m_speed                  = std::clamp(m_speed + (m_acceleration + friction) * dt, -MAX_SPEED, +MAX_SPEED);

    constexpr auto BREAK_POINT = 0.03f;
    if (m_acceleration == 0.f && std::abs(m_speed) < BREAK_POINT)
    {
        m_speed = 0.f;
    }

    const auto max_position = 1.f - m_size.x / 2.f;
    m_position              = std::clamp(m_position + m_speed * dt, -max_position, +max_position);
}