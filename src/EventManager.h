#pragma once

class Slider;

namespace sf {
class Window;
} // namespace sf

class EventManager
{
public:
    EventManager(sf::Window& window, Slider& slider);

    void ProcessEvents() const;

private:
    sf::Window& m_window;
    Slider& m_slider;
};
