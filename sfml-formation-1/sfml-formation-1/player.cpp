#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manager.h"

using namespace sf;
using namespace std;

Player::Player(){}

Sprite Player::recup_hero() 
{
    return hero;
}

void Player::normalize()
{

    float norme = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
    if (norme != 0)
    {
        velocity.x = ((velocity.x) / norme) * speed;
        velocity.y = ((velocity.y) / norme) * speed;
    }
    update_player_move();
}

void Player::update_player_position(int x, int y)
{
    hero.setPosition(x, y);
}

void Player::update_player_texture(Texture& texture)
{
    hero.setTexture(texture);
    
}

void Player::update_player_texture_rect(IntRect tile_hero)
{
    hero.setTextureRect(tile_hero);
    
}

void Player::update_player_scale(int scale_x, int scale_y)
{
    hero.setScale(scale_x, scale_y);
}

void Player::update_player_move()
{
    hero.move(velocity.x, velocity.y);
}


void Player::addHeroSprite()
{
    for (auto& tile : heroTiles)
    {
        IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
        
    }
}


void Player::anim_hero(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);

    if (activeKeys[DOWN])
    {
        cout << "DOWN" << endl;
        exKey = Keys::DOWN;
        if (velocity.y > 0)
        {
            cout << "velocity" << endl;
            if (manager.timer_player >= time1)
            {
                cout << "timer1" << endl;
                manager.timer_player = manager.clock.restart();

                hero.setTextureRect(IntRectHero["bas-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                cout << "timer2" << endl;
                hero.setTextureRect(IntRectHero["bas-1"]);
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
                hero.setTextureRect(IntRectHero["haut-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                hero.setTextureRect(IntRectHero["haut-1"]);
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
                hero.setTextureRect(IntRectHero["droite-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                hero.setTextureRect(IntRectHero["droite-1"]);
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
                hero.setTextureRect(IntRectHero["gauche-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                hero.setTextureRect(IntRectHero["gauche-1"]);
            }
        }

    }
    else if (exKey == Keys::DOWN)
    {
        hero.setTextureRect(IntRectHero["bas"]);
    }
    else if (exKey == Keys::UP)
    {
        hero.setTextureRect(IntRectHero["haut"]);
    }
    else if (exKey == Keys::RIGHT)
    {
        hero.setTextureRect(IntRectHero["droite"]);
    }
    else if (exKey == Keys::LEFT)
    {
        hero.setTextureRect(IntRectHero["gauche"]);
    }
}

void Player::recup_event_player(Event& event, RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
        window.close();
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKeys[UP] = true;
            cout << "ok" << endl;
        }
        else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
        {
            activeKeys[LEFT] = true;
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            activeKeys[DOWN] = true;
        }
        else if (event.key.code == sf::Keyboard::D)
        {
            activeKeys[RIGHT] = true;
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
}

void Player::check_stop_move()
{
    if (activeKeys[UP] == false) { velocity.y -= velocity.y; }
    if (activeKeys[LEFT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[RIGHT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[DOWN] == false) { velocity.y -= velocity.y; }

    if (activeKeys[UP]) { velocity.y -= speed; cout << "ooooooo" << endl; }
    if (activeKeys[LEFT]) { velocity.x -= speed; }
    if (activeKeys[RIGHT]) { velocity.x += speed; }
    if (activeKeys[DOWN]) { velocity.y += speed; }

}

void Player::limite_map()
{
    if (hero.getPosition().x <= 0)
    {
        hero.setPosition(0, hero.getPosition().y);
    }
    else if (hero.getPosition().x >= 720)
    {
        hero.setPosition(720, hero.getPosition().y);
    }
    else if (hero.getPosition().y <= 0)
    {
        hero.setPosition(hero.getPosition().x, 0);
    }
    else if (hero.getPosition().y >= 464)
    {
        hero.setPosition(hero.getPosition().x, 464);
    }
}