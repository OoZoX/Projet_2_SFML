#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player;
class Horse
{
private:
    sf::Sprite horse;
    bool player_horse = false;
    bool key_release_e = false;
    //sf::Vector2f velocity = { 0.0f, 0.0f };
    //float speed = 2.0f;

    std::map<std::string, sf::Vector2i> horseTiles = {
    {"bas", {}},
    {"bas-1", {}},
    {"bas-2", {}},
    {"gauche", {}},
    {"gauche-1", {}},
    {"gauche-2", {}},
    {"droite", {}},
    {"droite-1",{}},
    {"droite-2", {}},
    {"haut", {}},
    {"haut-1", {}},
    {"haut-2", {}}
    };

    std::map<std::string, sf::IntRect> IntRectHero;

public:
    Horse();

    sf::Sprite getHorse();

    void updateHorsePosition(int _x, int _y);
    void updateHorseTexture(sf::Texture& texture);
    void updateHorseTextureRect(sf::IntRect tile_hero);
    void updateHorseScale(int scale_x, int scale_y);
    void addHeroSprite();
    void dep_player_horse(Player&);
    void mont_horse(Player& player, sf::Event& event);
};