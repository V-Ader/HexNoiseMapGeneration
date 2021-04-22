#pragma once

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <cmath>

#include "../include/perlin.hpp"


class HexMap
{
private:
    //the size of display array
    sf::Vector2i size; 
    float *values;

    float scale;

    //global coords in hex of top left corner
    sf::Vector2f position;
   

public:
    HexMap(sf::Vector2i _size);
    ~HexMap();

    float getValue(sf::Vector2i position);
    void setValue(sf::Vector2i position, float _val);

    void setScale(float val, bool relative);

    void move(sf::Vector2f move, bool relative);
    sf::Vector2f getPosition();

    sf::Vector2f normalToHex(sf::Vector2i position);
    sf::Vector2i getSize();

};
