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

void Horse::addHorseSprite()
{
    for (auto& tile : horseTiles)
    {
        IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16 * 5, 16 * 5);

    }
}

bool Horse::dep_player_horse(Player& player)
{
    if (player_horse == true)
    {
        player.update_player_position(horse.getPosition().x + 15, horse.getPosition().y);
        player.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
        return true;
    }
    else {
        return false;
    }
}

void Horse::mont_horse(Player& player, Event& event)
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
                if (player_horse == false && key_release_e == false)
                {
                    player_horse = true;
                    key_release_e = true;
                }
                else if (player_horse == true)
                {
                    player_horse = false;
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
                key_release_e = false;
            }
        }
    }
}

void Horse::updateHorseMove(Manager& manager)
{
    horse.move(speed);
}

void Horse::getHorseEvent(Event& event, RenderWindow& window)
{
    poussee = 0.0f;
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKeys[UP] = true;
            poussee = 100;
        }
        else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
        {
            activeKeys[LEFT] = true;
            angle += 0.5;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            activeKeys[DOWN] = true;
            poussee = -100;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            activeKeys[RIGHT] = true;
            angle -= 0.5;
        }

    }
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKeys[UP] = false;
        }
        else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
        {
            activeKeys[LEFT] = false;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            activeKeys[DOWN] = false;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            activeKeys[RIGHT] = false;
        }
    }
    acceleration.x = ((1 / masse) * (poussee * cos(angle))) - ((12 / masse) * speed.x);
    acceleration.y = ((1 / masse) * (poussee * sin(angle))) - ((12 / masse) * speed.y);
    speed.x += acceleration.x; // * delta time
    speed.y += acceleration.y;
    cout << "speed : " << speed.x << "  " << speed.y << endl;
}

void Horse::horseAnimation(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);

    if (activeKeys[DOWN])
    {
        exKey = Keys::DOWN;
        if (velocity.y > 0)
        {
            if (manager.timer_player >= time1)
            {

                manager.timer_player = manager.clock.restart();

                horse.setTextureRect(IntRectHero["bas-2"]);

            }

            else if (manager.timer_player >= time2)
            {

                horse.setTextureRect(IntRectHero["bas-1"]);
            }
        }

    }
    else if (activeKeys[UP])
    {
        exKey = Keys::UP;
        if (velocity.y < 0)
        {
            if (manager.timer_player >= time1)
            {
                manager.timer_player = manager.clock.restart();
                horse.setTextureRect(IntRectHero["haut-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                horse.setTextureRect(IntRectHero["haut-1"]);
            }
        }


    }
    else if (activeKeys[RIGHT])
    {
        exKey = Keys::RIGHT;
        if (velocity.x > 0)
        {
            if (manager.timer_player >= time1)
            {
                manager.timer_player = manager.clock.restart();
                horse.setTextureRect(IntRectHero["droite-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                horse.setTextureRect(IntRectHero["droite-1"]);
            }
        }


    }
    else if (activeKeys[LEFT])
    {
        exKey = Keys::LEFT;
        if (velocity.x < 0)
        {
            if (manager.timer_player >= time1)
            {
                manager.timer_player = manager.clock.restart();
                horse.setTextureRect(IntRectHero["gauche-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                horse.setTextureRect(IntRectHero["gauche-1"]);
            }
        }

    }
    else if (exKey == Keys::DOWN)
    {
        horse.setTextureRect(IntRectHero["bas"]);
    }
    else if (exKey == Keys::UP)
    {
        horse.setTextureRect(IntRectHero["haut"]);
    }
    else if (exKey == Keys::RIGHT)
    {
        horse.setTextureRect(IntRectHero["droite"]);
    }
    else if (exKey == Keys::LEFT)
    {
        horse.setTextureRect(IntRectHero["gauche"]);
    }
}

void Horse::updateHorseVelocity()
{
    if (activeKeys[UP] == false) { velocity.y -= velocity.y; }
    if (activeKeys[LEFT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[RIGHT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[DOWN] == false) { velocity.y -= velocity.y; }

    if (activeKeys[UP]) { velocity.y -= speed.y; }
    if (activeKeys[LEFT]) { velocity.x -= speed.x; }
    if (activeKeys[RIGHT]) { velocity.x += speed.x; }
    if (activeKeys[DOWN]) { velocity.y += speed.y; }
}

void Horse::mapLimit()
{
    if (horse.getPosition().x <= 0)
    {
        horse.setPosition(0, horse.getPosition().y);
    }
    else if (horse.getPosition().x >= 716)
    {
        horse.setPosition(716, horse.getPosition().y);
    }
    else if (horse.getPosition().y <= 0)
    {
        horse.setPosition(horse.getPosition().x, 0);
    }
    else if (horse.getPosition().y >= 462)
    {
        horse.setPosition(horse.getPosition().x, 462);
    }
}