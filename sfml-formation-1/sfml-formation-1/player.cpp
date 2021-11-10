#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manager.h"

using namespace sf;
using namespace std;

Player Player::player(){}

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




void Player::moveHero(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);

    if (activeKeys[DOWN])
    {
        exKey = Keys::DOWN;
        if (velocity.y > 0)
        {
            if (timer >= time1)
            {
                timer = Manager::clock.restart();

                player.setTextureRect(IntRectHero["bas-2"]);
            }

            else if (timer >= time2)
            {
                player.setTextureRect(IntRectHero["bas-1"]);
            }
        }

    }
    else if (activeKeys[UP])
    {
        exKey = Keys::UP;
        if (velocity.y < 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                player.setTextureRect(IntRectHero["haut-2"]);
            }

            else if (timer >= time2)
            {
                player.setTextureRect(IntRectHero["haut-1"]);
            }
        }


    }
    else if (activeKeys[RIGHT])
    {
        exKey = Keys::RIGHT;
        if (velocity.x > 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                player.setTextureRect(IntRectHero["droite-2"]);
            }

            else if (timer >= time2)
            {
                player.setTextureRect(IntRectHero["droite-1"]);
            }
        }


    }
    else if (activeKeys[LEFT])
    {
        exKey = Keys::LEFT;
        if (velocity.x < 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                player.setTextureRect(IntRectHero["gauche-2"]);
            }

            else if (timer >= time2)
            {
                player.setTextureRect(IntRectHero["gauche-1"]);
            }
        }

    }
    else if (exKey == Keys::DOWN)
    {
        player.setTextureRect(IntRectHero["bas"]);
    }
    else if (exKey == Keys::UP)
    {
        player.setTextureRect(IntRectHero["haut"]);
    }
    else if (exKey == Keys::RIGHT)
    {
        player.setTextureRect(IntRectHero["droite"]);
    }
    else if (exKey == Keys::LEFT)
    {
        player.setTextureRect(IntRectHero["gauche"]);
    }
}