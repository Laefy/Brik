#include "EventManager.h"

#include "Slider.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>

namespace {

float GetSliderAcceleration(sf::Keyboard::Key key)
{
    return sf::Keyboard::isKeyPressed(key) ? 1.f : 0.f;
}

} // namespace

EventManager::EventManager(sf::Window& window, Slider& slider) : m_window { window }, m_slider { slider }
{}

void EventManager::ProcessEvents() const
{
    sf::Event event;

    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;

        default:
            break;
        }
    }

    const auto slider_acc = -GetSliderAcceleration(sf::Keyboard::Left) + GetSliderAcceleration(sf::Keyboard::Right);
    m_slider.SetAcceleration(slider_acc);
}
