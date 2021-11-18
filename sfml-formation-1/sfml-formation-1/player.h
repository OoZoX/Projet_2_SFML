#pragma once
#include <map>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "manager.h"

class Horse;
class Epee;
class Ennemy;
class HealthBar;

enum Keys { UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX };

class Player : public Manager
{

private:
	sf::Sprite hero;

    sf::Vector2f velocity = {0.0f, 0.0f};
    float speed = 2.0f;

    int compt_domage = 0;

    bool check_colis_epee = false;
    bool epee_ramas = false;
    bool check_attaque_player = false;
    bool debut_att = false;
    bool check_mort = false;

    float rota_epee;
    float rota_arrive;
    float ex_rota;

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

    Epee* ptr_epee = nullptr;

public:
    Player();

    sf::Sprite recup_hero();

    std::map<std::string, sf::IntRect> getIntRect();

    void update_player_position(int _x, int _y);

    void update_player_texture(sf::Texture& texture);

    void update_player_texture_rect(sf::IntRect tile_hero);

    void update_player_scale(int scale_x, int scale_y);

    void update_player_move(Manager& manager);

    void addHeroSprite();

    void anim_hero(Manager& manager);

    void recup_event_player(sf::Event& event, sf::RenderWindow& window);

    void modif_velocity_player();

    float recup_speed();

    sf::Vector2f recup_position();

    sf::Vector2f getVelocity();

    void checkCollision(Horse& horse, Ennemy& ennemy, Epee& epee, HealthBar& bar);

    void compt_time();

    void limite_map();

    void recup_epee(sf::Event& event, Epee& epee);

    void update_pos_epee(Epee& epee);

    void get_event_attaque(sf::Event& event);

    void attaque(Epee& epee);

    Keys recup_activ_key();

    bool recup_attaque();

    void check_dead(HealthBar& vie);

    bool get_check_mort();

};
