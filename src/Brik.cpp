#include "EventManager.h"
#include "Slider.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window { sf::VideoMode(800, 600), "Brik" };

    sf::View view;
    view.setCenter(sf::Vector2f { 0, 0 });
    view.setSize(sf::Vector2f { 2, -2 });
    window.setView(view);

    Slider slider;

    EventManager event_manager { window, slider };

    sf::Clock clock;
    while (window.isOpen())
    {
        const auto dt = clock.getElapsedTime().asSeconds();
        clock.restart();

        event_manager.ProcessEvents();

        slider.Update(dt);

        window.clear();
        slider.Render(window);
        window.display();
    }

    return 0;
}