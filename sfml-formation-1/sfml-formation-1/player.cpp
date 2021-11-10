#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

void Player::normalize()
{

    float norme = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
    if (norme != 0)
    {
        velocity.x = ((velocity.x) / norme) * speed;
        velocity.y = ((velocity.y) / norme) * speed;
    }
}

void Player::update_player(Sprite update_player)
{
    player = update_player;
}


void Player::addHeroSprite()
{
    map<string, IntRect> local_IntRectHero;

    for (auto& tile : heroTiles)
    {
        local_IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }

     IntRectHero = local_IntRectHero;
}