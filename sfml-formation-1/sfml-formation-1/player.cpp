#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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