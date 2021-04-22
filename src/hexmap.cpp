#include "../include/hexmap.hpp"

HexMap::HexMap(sf::Vector2i _size)
{
    this->size = _size;
    this->scale = 0.10f;
    this->values = (float*)malloc(sizeof(float)*(_size.x * _size.y));


    for(int i = 0; i < _size.x; ++i)
    {
        for(int j = 0; j < _size.y; ++j)
        {
            this->setValue(sf::Vector2i(i, j), 1);
        }
    }
}

HexMap::~HexMap()
{
    delete values;
}

float HexMap::getValue(sf::Vector2i position)
{
    return this->values[position.x+this->size.x*position.y];
}

void HexMap::setValue(sf::Vector2i position, float _val)
{
    sf::Vector2f temp = this->normalToHex(sf::Vector2i(position.x, position.y));
    this->values[position.x+this->size.x*position.y] = perlin(
        (this->position.x+temp.x)*this->scale, 
        (this->position.y+temp.y)*this->scale);


}

sf::Vector2f HexMap::getPosition()
{
    return this->position;
}

void HexMap::setScale(float val, bool relative)
{
    if(relative)
    {
        this->scale += val;

        this->move(sf::Vector2f(
            this->size.x/2,
            this->size.y/2), 
            false);

    }
    else
    {
        this->scale = val;
    }
    
    std::cout << "scale: " << this->scale << std::endl;
    std::cout << "positoin: " << this->position.x << " " << this->position.y << std::endl;
    std::cout << "size: " << this->size.x << " " << this->size.y << std::endl << std::endl;
}

void HexMap::move(sf::Vector2f move, bool relative)
{
    std::cout << move.x << " " << move.y << std::endl;
    move.y *= sqrt(3);
    //move.x *= this->scale;
    if(relative)
        this->position += move;
    else
        this->position = move;
}


sf::Vector2f HexMap::normalToHex(sf::Vector2i position)
{
    if(position.x%2 == 0)
        return sf::Vector2f(
            (float)3/2 * (float) position.x,
            (float) sqrt(3)*(float) position.y
            );
    else
        return sf::Vector2f(
            (position.x - 1) * 3/2 + (float)3/2 ,
            sqrt(3) * (position.y) + (float)sqrt(3)/2);
    
}

sf::Vector2i HexMap::getSize(){
    return this->size;
}