#include "EventManager.h"
#include "Map.h"
#include "Slider.h"

#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window { sf::VideoMode(800, 600), "Brik" };

    sf::View view;
    view.setCenter(sf::Vector2f { 0, 0 });
    view.setSize(sf::Vector2f { 2, -2 });
    window.setView(view);

    Map map;
    map.Load("assets/map1.brik");

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
        map.Render(window);
        slider.Render(window);
        window.display();

        const auto min_frame_dt = sf::milliseconds(1'000 / 60);
        const auto final_dt     = clock.getElapsedTime();
        if (final_dt < min_frame_dt)
        {
            sf::sleep(min_frame_dt - final_dt);
        }
    }

    return 0;
}