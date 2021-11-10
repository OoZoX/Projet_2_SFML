#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
class Player
{
private:
	sf::Sprite player;
    sf::Vector2f velocity = {0.0f, 0.0f};
    float speed;

	std::map<std::string, sf::Vector2i> heroTiles = {
    {"bas", {1,0}},
    {"bas-1", {0,0}},
    {"bas-2", {2,0}},
    {"gauche", {1,1}},
    {"gauche-1", {0,1}},
    {"gauche-2", {2,1}},
    {"droite", {1,2}},
    {"droite-1",{0,2}},
    {"droite-2", {2,2}},
    {"haut", {1,3}},
    {"haut-1", {0,3}},
    {"haut-2", {2,3}}
    };

    void normalize();
};
