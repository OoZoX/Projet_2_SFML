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
    bool isMounted = false;
    bool keyRelease = false;
    bool activeKey[KEY_MAX] = { false };
    Keys exKey = DOWN;
    sf::Vector2f speed = { 0.0f, 0.0f };
    sf::Vector2f acceleration = {0.0f, 0.0f };
    float masse = 150.0f;
    float poussee = 0.0f;
    float angle = 0.0f;
    std::map<std::string, sf::Vector2i> horseTiles = {
    {"bas", {0, 0}},
    {"bas-1", {0, 5}},
    {"bas-2", {0, 10}},
    {"droite", {15, 0}},
    {"droite-1",{5, 0}},
    {"droite-2", {5, 5}},
    {"haut", {20, 0}},
    {"haut-1", {10, 5}},
    {"haut-2", {10, 10}}
    };
    std::map<std::string, sf::IntRect> IntRectHorse;

public:
    Horse();
    sf::Sprite getHorse();
    void setHorseSprite();
    void updateHorsePosition(int _x, int _y);
    void updateHorseOrigin(int x, int y);
    void updateHorseTexture(sf::Texture& texture);
    void updateHorseTextureRect(sf::IntRect tile_hero);
    void updateHorseScale(int scale_x, int scale_y);
    sf::Vector2f getSpeed();
    sf::Vector2f getPosition();
    void getHorseEvent(sf::Event& event, sf::RenderWindow& window);
    bool playerOnHorse(Player&);
    void mountHorse(Player& player, sf::Event& event);
    void updateHorseMove(Manager& manager);
    void horseAnimation(Manager& manager, Player& player);
    void mapLimit();
};