#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

#include "../include/hexmap.hpp"



class Window
{
private:

	sf::RenderWindow window;

    HexMap *map;

    sf::Sprite spr;
    sf::Texture bcgTexture;


public:

    Window(HexMap *_map);
    
    ~Window();

    bool isOpen();

    void update(float dt);

    void render();

    void handleEvents();

};
