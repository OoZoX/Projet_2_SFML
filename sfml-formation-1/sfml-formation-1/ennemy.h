#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "manager.h"

class Ennemy : public Manager
{
private:
    sf::Sprite _ennemy;

    std::map<std::string, sf::IntRect> IntRectEnnemy;

    std::map<std::string, sf::Vector2i> ennemyTiles = {
    {"bas", {1,4}},
    {"bas-1", {0,4}},
    {"bas-2", {2,4}},
    {"gauche", {1,5}},
    {"gauche-1", {0,5}},
    {"gauche-2", {2,5}},
    {"droite", {1,6}},
    {"droite-1",{0,6}},
    {"droite-2", {2,6}},
    {"haut", {1,7}},
    {"haut-1", {0,7}},
    {"haut-2", {2,7}}
    };

public:
    Ennemy();
    sf::Sprite recup_sprite_ennemy();
    void addEnnemySprite();
    void moveEnnemy(Manager& manager);
    void move();
    void update_ennemy_texture(sf::Texture texture);
    void update_ennemy_texture_rect(sf::IntRect tile_ennemy);
    void update_ennemy_scale(int x, int y);
    void update_ennemy_position(int x, int y);
};

