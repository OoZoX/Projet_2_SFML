#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

enum Keys { UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX };

class Player
{

private:
	sf::Sprite player;
    sf::Vector2f velocity = {0.0f, 0.0f};
    float speed;

    bool activeKeys[KEY_MAX] = { false };

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

    std::map<std::string, sf::IntRect> IntRectHero;

public:
    void normalize();

    void update_player(sf::Sprite update_player);

    void addHeroSprite();
};
