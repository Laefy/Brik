#include "Breakable.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

Breakable::Breakable(size_t x, size_t y) : m_position { -1.f + SIZE.x * x, 1.f - SIZE.y * y }
{}

void Breakable::Render(sf::RenderTarget& target) const
{
    {
        sf::RectangleShape outer { SIZE };
        outer.setOrigin(sf::Vector2 { 0.f, SIZE.y });
        outer.setPosition(m_position);
        outer.setFillColor(sf::Color::Cyan);

        target.draw(outer);
    }

    {
        const sf::Vector2 thickness { 0.01f, 0.015f };
        sf::RectangleShape inner { SIZE - 2.f * thickness };
        inner.setOrigin(sf::Vector2 { 0.f, SIZE.y });
        inner.setPosition(m_position + thickness);
        inner.setFillColor(sf::Color::Blue);

        target.draw(inner);
    }
}
