#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "horse.h"
#include "ennemy.h"
#include "epee.h"
#include "health_bar.h"

using namespace sf;
using namespace std;

Player::Player(){}

Sprite Player::recup_hero() 
{
    return hero;
}

map<string, IntRect> Player::getIntRect()
{
    return IntRectHero;
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

void Player::update_player_move(Manager& manager)
{
    if (sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y)) != 0)
    {
        velocity = manager.normalize(velocity, speed);
    }
    hero.move(velocity);
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
        exKey = Keys::DOWN;
        if (velocity.y > 0)
        {
            if (manager.timer_player >= time1)
            {
                
                manager.timer_player = manager.clock.restart();

                hero.setTextureRect(IntRectHero["bas-2"]);
            }

            else if (manager.timer_player >= time2)
            {
                
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
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
        {
            activeKeys[UP] = true;
            
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

void Player::modif_velocity_player()
{
    if (activeKeys[UP] == false) { velocity.y -= velocity.y; }
    if (activeKeys[LEFT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[RIGHT] == false) { velocity.x -= velocity.x; }
    if (activeKeys[DOWN] == false) { velocity.y -= velocity.y; }

    if (activeKeys[UP]) { velocity.y -= speed; }
    if (activeKeys[LEFT]) { velocity.x -= speed; }
    if (activeKeys[RIGHT]) { velocity.x += speed; }
    if (activeKeys[DOWN]) { velocity.y += speed; }

}

float Player::recup_speed()
{
    return speed;
}

Vector2f Player::recup_position()
{
    return hero.getPosition();
}

Vector2f Player::getVelocity()
{
    return velocity;
}

void Player::checkCollision(Horse& horse, Ennemy& ennemy, Epee& epee, HealthBar& bar)
{
    Sprite horseSprite = horse.getHorse();
    Sprite ennemySprite = ennemy.recup_sprite_ennemy();
    Sprite epeeSprite = epee.recup_epee();
    FloatRect(0, 0, 0, 0);
    if (hero.getGlobalBounds().intersects(horseSprite.getGlobalBounds()))
    {
    }
    if (hero.getGlobalBounds().intersects(ennemySprite.getGlobalBounds()))
    {
        if (compt_domage == 0)
        {
            bar.chang_vie();
            compt_domage++;
        }
        
    }

    if (hero.getGlobalBounds().intersects(epeeSprite.getGlobalBounds()))
    {
        check_colis_epee = true;
    }
    else
    {
        check_colis_epee = false;
    }
}

void Player::compt_time()
{
    if (compt_domage != 0)
    {
        compt_domage++;

        if (compt_domage >= 60)
        {
            compt_domage = 0;
        }
    }
    
}


void Player::limite_map()
{
    if (hero.getPosition().x <= 0)
    {
        hero.setPosition(0, hero.getPosition().y);
    }
    if (hero.getPosition().x >= 724)
    {
        hero.setPosition(724, hero.getPosition().y);
    }
    if (hero.getPosition().y <= 0)
    {
        hero.setPosition(hero.getPosition().x, 0);
    }
    if (hero.getPosition().y >= 462)
    {
        hero.setPosition(hero.getPosition().x, 462);
    }
}

void Player::recup_epee(Event& event, Epee& epee)
{
    if (check_colis_epee)
    {
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::E)
            {
                if (!epee_ramas)
                {
                    Vector2f pos = hero.getPosition();
                    epee_ramas = true;
                    epee.set_placement(pos.x + 23, pos.y + 20);
                    epee.set_rotate(0);
                }
            }
        }
    }
}

void Player::update_pos_epee(Epee& epee)
{
    Vector2f pos = hero.getPosition();
    if (epee_ramas)
    {
        if (activeKeys[UP] && activeKeys[RIGHT])
        {
            epee.set_placement(pos.x + 20, pos.y + 25);
            epee.set_rotate(45);
        }
        else if (activeKeys[UP] && activeKeys[LEFT])
        {
            epee.set_placement(pos.x + 25, pos.y + 25);
            epee.set_rotate(-45);
        }
        else if (activeKeys[DOWN] && activeKeys[LEFT])
        {
            epee.set_placement(pos.x + 25, pos.y + 30);
            epee.set_rotate(-135);
        }
        else if (activeKeys[DOWN] && activeKeys[RIGHT])
        {
            epee.set_placement(pos.x + 25, pos.y + 30);
            epee.set_rotate(135);
        }
        else if (activeKeys[UP])
        {
            epee.set_placement(pos.x + 23, pos.y + 20);
            epee.set_rotate(0);

        }
        else if (activeKeys[RIGHT])
        {
            epee.set_placement(pos.x + 15 , pos.y + 35);
            epee.set_rotate(90);
        }
        else if (activeKeys[LEFT])
        {

            epee.set_placement(pos.x + 35, pos.y +35);
            epee.set_rotate(-90);
        }
        else if (activeKeys[DOWN])
        {

            epee.set_placement(pos.x + 35 , pos.y + 27);
            epee.set_rotate(180);
        }
    }
}
void Player::get_event_attaque(Event& event)
{
    if (event.type == Event::KeyPressed)
    {
        if (event.key.code == Keyboard::Space)
        {
            check_attaque_player = true;
        }
    }
}
void Player::attaque(Epee& epee)
{
    if (check_attaque_player)
    {
        if (debut_att)
        {
            rota_epee += 5;
            epee.set_rotate(rota_epee + epee.get_rotate());
            if (rota_epee >= rota_arrive)
            {
                check_attaque_player = false;
                debut_att = false;
                epee.set_rotate(ex_rota);

            }
        }
        else
        {
            
            ex_rota = epee.get_rotate();
            rota_epee = 0;
            debut_att = true;
            rota_arrive = 40;
        }
    }
}

Keys Player::recup_activ_key()
{
    return exKey;
}

bool Player::recup_attaque()
{
    return check_attaque_player;
}

void Player::check_dead(HealthBar& vie)
{
    if (vie.get_vie() <= 0)
    {
        check_mort = true;
    }
}

bool Player::get_check_mort()
{
    return check_mort;
}