#include "horse.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

Horse::Horse() {}

Sprite Horse::getHorse()
{
    return horse;
}


void Horse::updateHorsePosition(int x, int y)
{
    horse.setPosition(x, y);
}

void Horse::updateHorseTexture(Texture& texture)
{
    horse.setTexture(texture);

}

void Horse::updateHorseTextureRect(IntRect tile_hero)
{
    horse.setTextureRect(tile_hero);

}

void Horse::updateHorseScale(int scale_x, int scale_y)
{
    horse.setScale(scale_x, scale_y);
}

void Horse::addHeroSprite()
{
    for (auto& tile : horseTiles)
    {
        IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);

    }
}