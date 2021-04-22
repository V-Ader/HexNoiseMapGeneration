#include "window.hpp"
#include <iostream>

#define SCALE  0.1

Window::Window(HexMap *_map)
{
    window.setKeyRepeatEnabled(true);

    //this->spr.setTexture(system->bcgTexture);
    this->map = _map;

	this->window.create(sf::VideoMode(720, 720), "noise");
	window.setFramerateLimit(30);

}

Window::~Window()
{
}

bool Window::isOpen() {
    return this->window.isOpen();
}

void Window::update(float dt)
{
    for(int i = 0; i < this->map->getSize().x; ++i)
    {
        for(int j = 0; j < this->map->getSize().y; ++j)
        {
            this->map->setValue(sf::Vector2i(i, j), 1);
        }
    }
}

void Window::handleEvents()
{   

    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) this->window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            this->map->move(sf::Vector2f(-1,0), true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            this->map->move(sf::Vector2f(1,0), true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            this->map->move(sf::Vector2f(0,1), true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            this->map->move(sf::Vector2f(0,-1), true);
        }

        if (event.type == sf::Event::MouseWheelMoved)
        {
            this->map->setScale((float)event.mouseWheel.delta/200, true);
        }

    }
}


void Window::render()
{
    this->window.clear(sf::Color::Black);
    sf::RectangleShape rectangle(sf::Vector2f(10, 10));
    sf::CircleShape hex(10,6);
    hex.setOrigin(5,5);
    hex.rotate(30.0f);
    //hex.scale(2.0f, 2.0f);

    

    sf::Vector2f start(20.0f, 20.0f);

    for(int i = 0; i < this->map->getSize().x; ++i)
    {
        for(int j = 0; j < this->map->getSize().y; ++j)
        {
            sf::Vector2f temp = this->map->normalToHex(sf::Vector2i(i, j));

            hex.setPosition(start.x + (float)temp.x*11, start.y + (float)temp.y*11);

            int c = (this->map->getValue(sf::Vector2i(i, j))) *255;
            //int c = 255;
            hex.setFillColor(sf::Color(c, c, c));
            this->window.draw(hex);

        }
    }


    this->window.display();
}