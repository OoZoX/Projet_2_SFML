#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "manager.h"

class Ennemy : public Manager
{
private:
    sf::Sprite _ennemy;
    sf::Time timer_deplacement;
    float speed = 1.5;
    int index = 0;
    bool check_calcul = false;
    bool check_mort = false;
    sf::Vector2f velocity = { 0.0f, 0.0f };

    std::map<std::string, sf::IntRect> IntRectEnnemy;

    std::map<std::string, sf::Vector2i> ennemyTiles;

    std::vector<sf::Vector2f> chemin;

public:
    Ennemy();
    sf::Sprite recup_sprite_ennemy();
    void addEnnemySprite();
    void anim_ennemy(Manager& manager);
    void move();
    void update_ennemy_texture(sf::Texture& texture);
    void update_ennemy_texture_rect(sf::IntRect tile_ennemy);
    void update_ennemy_scale(int x, int y);
    void update_ennemy_position();
    void deplacement_ennemy(Manager& manager);
    void set_navigation_ennemi(std::vector<sf::Vector2f>);
    void set_tile_anim(std::map<std::string, sf::Vector2i>);
    void set_mort();
    bool get_mort();
};

