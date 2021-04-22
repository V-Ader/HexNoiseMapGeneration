#include "window.hpp"
#include <iostream>

#define SCALE  0.1

Window::Window(int size, std::set<Point> &points, sf::Vector2f &pos, sf::Vector2f &off)
: points(points), position(pos), offset(off)
{
    window.setKeyRepeatEnabled(true);


    this->size = size;
    this->type = 1;


    //this->spr.setTexture(system->bcgTexture);

	this->window.create(sf::VideoMode(720, 720), "noise");
	window.setFramerateLimit(30);

}

Window::~Window()
{
    delete this->arr;

}

bool Window::isOpen() {
    return this->window.isOpen();
}

void Window::update(float dt)
{
    for(auto& point : points ){
       point.val = 1;
    }
}

void Window::handleEvents(sf::Vector2f &pos)
{   

    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) this->window.close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            pos.x += 1;
            std::cout << "*";

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {

            std::cout << pos.x << std::endl;

        }
    }


}


void Window::render()
{
    this->window.clear(sf::Color::Black);
    sf::RectangleShape rectangle(sf::Vector2f(10, 10));
    sf::CircleShape hex(10,6);


    switch (this->type)
    {
    case 0:
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                //std::cout << arr[i+20*j] << " ";
                rectangle.setPosition((float)i*11, (float)j*11);

                int c = (arr[i+this->size*j]+1) * 255;
                rectangle.setFillColor(sf::Color(c, c, c));

                this->window.draw(rectangle);
            }
        }
        break;
    case 1:
        for(auto& point : points ){

            hex.setPosition(point.x*21 + 360, point.y*21 + 360);
                int c = (point.val+1) * 255;
                //c = 255;
                hex.setFillColor(sf::Color(c, c, c));

                this->window.draw(hex);
        }
    break;
    
    default:
        break;
    }

    this->window.display();
}