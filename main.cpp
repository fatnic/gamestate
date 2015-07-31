#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "test_state.h"

game_state corestate;

int main()
{
    sf::RenderWindow window(sf::VideoMode(720,480), "GameWindow");

    corestate.setWindow(&window);
    corestate.setState(new test_state());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        corestate.Update();
        corestate.Render();
        window.display();
    }

    return 0;
}
