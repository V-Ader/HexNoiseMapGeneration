
#include <set>
#include <tuple>
#include <iostream>

#define PI 3.1415

#include "../include/window.hpp"
#include "../include/hexmap.hpp"

#define SIZE 60
#define MAX 100
#define SCALE 0.1



int main()
{
    sf::Vector2f position(0.0f, 0.0f);
    sf::Vector2f offset(0.0f, 0.0f);

    HexMap map(sf::Vector2i(40, 40));
    std::cout << map.getValue(sf::Vector2i(4,2));

    Window window(&map);

    while(window.isOpen())
    {
        window.handleEvents();

        window.update(0.0f);

        window.render();
    }

    return 0;
}