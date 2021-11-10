#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manager.h"


enum Keys { UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX };

class Player : public Manager
{

private:
	sf::Sprite hero;

    sf::Vector2f velocity = {0.0f, 0.0f};
    float speed = 2.0f;

    bool activeKeys[KEY_MAX] = { false };
    Keys exKey = DOWN;

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
    Player();

    sf::Sprite recup_hero();

    void normalize();

    void update_player_position(int _x, int _y);

    void update_player_texture(sf::Texture texture);

    void update_player_texture_rect(sf::IntRect tile_hero);

    void update_player_scale(int scale_x, int scale_y);

    void addHeroSprite();

    void moveHero(Manager& manager);

    void recup_event_player(sf::Event& event, sf::RenderWindow& window);

    void check_stop_move();

    void limite_map();

};
