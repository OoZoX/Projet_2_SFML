#pragma once
#include "manager.h"
#include "player.h"
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player;

class Horse : public Manager
{
private:
    sf::Sprite horse;
    bool player_horse = false;
    bool key_release_e = false;
    bool activeKeys[KEY_MAX] = { false };
    Keys exKey = DOWN;

    sf::Vector2f velocity = { 0.0f, 0.0f };
    float speed = 2.0f;

    std::map<std::string, sf::Vector2i> horseTiles = {
    {"bas", {0, 0}},
    {"bas-1", {0, 2}},
    {"bas-2", {0, 3}},
    {"droite", {3, 0}},
    {"droite-1",{1, 0}},
    {"droite-2", {1, 3}},
    {"haut", {3, 0}},
    {"haut-1", {2, 1}},
    {"haut-2", {2, 2}}
    };

    std::map<std::string, sf::IntRect> IntRectHero;

public:
    Horse();
    sf::Sprite getHorse();
    void updateHorsePosition(int _x, int _y);
    void updateHorseTexture(sf::Texture& texture);
    void updateHorseTextureRect(sf::IntRect tile_hero);
    void updateHorseScale(int scale_x, int scale_y);
    void addHorseSprite();
    bool dep_player_horse(Player&);
    void mont_horse(Player& player, sf::Event& event);
    void updateHorseMove(Manager& manager);
    void getHorseEvent(sf::Event& event, sf::RenderWindow& window);
    void horseAnimation(Manager& manager);
    void updateHorseVelocity();
    void mapLimit();
};