#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include "manager.h"

class Ennemy : public Manager
{
private:
    sf::Sprite ennemy;
    sf::Time movementTimer;
    float speed = 1.5;
    int index = 0;
    bool checkCalcul = false;
    bool checkDeath = false;
    sf::Vector2f velocity = { 0.0f, 0.0f };
    std::map<std::string, sf::IntRect> IntRectEnnemy;
    std::map<std::string, sf::Vector2i> ennemyTiles;
    std::vector<sf::Vector2f> path;

public:
    Ennemy();
    sf::Sprite getEnnemySprite();
    void addEnnemySprite();
    void setPath(std::vector<sf::Vector2f>);
    void setEnnemyTiles(std::map<std::string, sf::Vector2i>);
    void setDeath();
    bool getDeath();
    void updateEnnemyTexture(sf::Texture& texture);
    void updateEnnemyTextureRect(sf::IntRect tile_ennemy);
    void updateEnnemyScale(int x, int y);
    void updateEnnemyPosition();
    void move(Manager& manager);
    void ennemyAnimation(Manager& manager);
};

