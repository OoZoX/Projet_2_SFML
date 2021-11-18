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

void Horse::setHorseSprite()
{
    for (auto& tile : horseTiles)
    {
        IntRectHorse[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16 * 5, 16 * 5);
    }
}

void Horse::updateHorsePosition(int x, int y)
{
    horse.setPosition(x, y);
}

void Horse::updateHorseOrigin(int x, int y)
{
    horse.setOrigin(x, y);
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

Vector2f Horse::getSpeed()
{
    return speed;
}

Vector2f Horse::getPosition()
{
    return horse.getPosition();
}

void Horse::getHorseEvent(Event& event, RenderWindow& window)
{
    poussee = 0.0f;
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKey[UP] = true;
            poussee = 100;
        }
        else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
        {
            activeKey[LEFT] = true;
            angle += 0.5;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            activeKey[DOWN] = true;
            poussee = -100;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            activeKey[RIGHT] = true;
            angle -= 0.5;
        }

    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKey[UP] = false;
        }
        else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
        {
            activeKey[LEFT] = false;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            activeKey[DOWN] = false;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            activeKey[RIGHT] = false;
        }
    }
    acceleration.x = ((1 / masse) * (poussee * cos(angle))) - ((12 / masse) * speed.x);
    acceleration.y = ((1 / masse) * (poussee * sin(angle))) - ((12 / masse) * speed.y);
    speed.x += acceleration.x;
    speed.y += acceleration.y;
}

bool Horse::playerOnHorse(Player& player)
{
    if (isMounted == true)
    {
        player.update_player_position(horse.getPosition().x + 15, horse.getPosition().y);
        player.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
        return true;
    }
    else {
        return false;
    }
}

void Horse::mountHorse(Player& player, Event& event)
{
    Vector2f pos_player;
    pos_player.x = player.recup_position().x;
    pos_player.y = player.recup_position().y;

    if (((pos_player.x - horse.getPosition().x) <= 50.0f && (pos_player.y - horse.getPosition().y) <= 50.0f) && ((pos_player.x - horse.getPosition().x) >= -50.0f && (pos_player.y - horse.getPosition().y) >= -50.0f))
    {
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::E)
            {
                if (isMounted == false && keyRelease == false)
                {
                    isMounted = true;
                    keyRelease = true;
                }
                else if (isMounted == true)
                {
                    isMounted = false;
                    speed = { 0.0f, 0.0f };
                    acceleration = { 0.0f, 0.0f };
                    poussee = 0.0f;
                    angle = 0.0f;
                    player.update_player_position(player.recup_position().x + 10.0f, player.recup_position().y + 10.0f);
                }
            }
        }
        if (event.type == Event::KeyReleased)
        {
            if (event.key.code == Keyboard::E)
            {
                keyRelease = false;
            }
        }
    }
}

void Horse::updateHorseMove(Manager& manager)
{
    horse.move(speed);
}

void Horse::horseAnimation(Manager& manager, Player& player)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);

    if (playerOnHorse(player))
    {
        if (activeKey[DOWN])
        {
            exKey = Keys::DOWN;
            if (speed.y > 0 && speed.x < speed.y)
            {
                if (manager.timer_player >= time1)
                {

                    manager.timer_player = manager.clock.restart();

                    horse.setTextureRect(IntRectHorse["bas-2"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 0);
                    player.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));

                }

                else if (manager.timer_player >= time2)
                {

                    horse.setTextureRect(IntRectHorse["bas-1"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 0);
                    player.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
                }
            }

        }
        else if (activeKey[UP])
        {
            exKey = Keys::UP;
            if (speed.y < 0 && speed.x < speed.y)
            {
                if (manager.timer_player >= time1)
                {
                    manager.timer_player = manager.clock.restart();
                    horse.setTextureRect(IntRectHorse["haut-2"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 10);
                    player.update_player_texture_rect(IntRect(1 * 16, 3 * 16, 16, 16));
                }

                else if (manager.timer_player >= time2)
                {
                    horse.setTextureRect(IntRectHorse["haut-1"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 0);
                    player.update_player_texture_rect(IntRect(1 * 16, 3 * 16, 16, 16));
                }
            }


        }
        else if (activeKey[RIGHT])
        {
            exKey = Keys::RIGHT;
            if (speed.x > 0 && speed.y < speed.x)
            {
                if (manager.timer_player >= time1)
                {
                    manager.timer_player = manager.clock.restart();
                    horse.setTextureRect(IntRectHorse["droite-2"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 10);
                    player.update_player_texture_rect(IntRect(1 * 16, 2 * 16, 16, 16));
                }

                else if (manager.timer_player >= time2)
                {
                    horse.setTextureRect(IntRectHorse["droite-1"]);
                    horse.setScale(1, 1);
                    horse.setOrigin(0, 10);
                    player.update_player_texture_rect(IntRect(1 * 16, 2 * 16, 16, 16));
                }
            }


        }
        else if (activeKey[LEFT])
        {
            exKey = Keys::LEFT;
            if (speed.x < 0 && speed.y < speed.x)
            {
                if (manager.timer_player >= time1)
                {
                    manager.timer_player = manager.clock.restart();
                    horse.setTextureRect(IntRectHorse["droite"]);
                    horse.setScale(-1, 1);
                    horse.setOrigin(16 * 4.75, 10);
                    player.update_player_texture_rect(IntRect(1 * 16, 1 * 16, 16 * 5, 16 * 5));
                }

                else if (manager.timer_player >= time2)
                {
                    horse.setTextureRect(IntRectHorse["droite"]);
                    horse.setScale(-1, 1);
                    horse.setOrigin(16 * 4.75, 10);
                    player.update_player_texture_rect(IntRect(1 * 16, 1 * 16, 16, 16));
                }
            }

        }
        else if (exKey == Keys::DOWN)
        {
            horse.setTextureRect(IntRectHorse["bas"]);
            horse.setScale(1, 1);
            horse.setOrigin(0, 0);
            player.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
        }
        else if (exKey == Keys::UP)
        {
            horse.setTextureRect(IntRectHorse["haut"]);
            horse.setScale(1, 1);
            horse.setOrigin(0, 0);
            player.update_player_texture_rect(IntRect(1 * 16, 3 * 16, 16, 16));
        }
        else if (exKey == Keys::RIGHT)
        {
            horse.setTextureRect(IntRectHorse["droite"]);
            horse.setScale(1, 1);
            horse.setOrigin(0, 10);
            player.update_player_texture_rect(IntRect(1 * 16, 2 * 16, 16, 16));
        }
        else if (exKey == Keys::LEFT)
        {
            horse.setTextureRect(IntRectHorse["droite"]);
            horse.setScale(-1, 1);
            horse.setOrigin(16*4.75, 10);
            Sprite playerr = player.recup_hero();
            playerr.setTextureRect(IntRect(1 * 16 * 0, 1 * 16, 16, 16));
        }
    }
}

void Horse::mapLimit()
{
    if (horse.getPosition().x <= 0)
    {
        horse.setPosition(0, horse.getPosition().y);
    }
    if (horse.getPosition().x >= 716)
    {
        horse.setPosition(716, horse.getPosition().y);
    }
    if (horse.getPosition().y <= 0)
    {
        horse.setPosition(horse.getPosition().x, 0);
    }
    if (horse.getPosition().y >= 462)
    {
        horse.setPosition(horse.getPosition().x, 462);
    }
}