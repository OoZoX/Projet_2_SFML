#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

class Ennemy
{
private:
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
    void addEnnemySprite();
};

