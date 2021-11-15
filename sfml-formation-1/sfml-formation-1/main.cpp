#include <SFML/Graphics.hpp>
#include "manager.h"
#include "player.h"
#include "horse.h"
#include "ennemy.h"
#include "level.h"


#include <map>
#include <iostream>

using namespace sf;
using namespace std;

typedef Vector2f vec2;
typedef Vector2i vec2i;


int main()
{
    sf::Event event;

    RenderWindow window(VideoMode(768, 512), "SFML works!");    //768, 512
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

    Manager manager;    // creation manager

    Level level;    //creation map 
    Texture mapTexture;
    mapTexture.loadFromFile("foresttiles2-t.png");     // set la texture 
    level.displayLevel(mapTexture); // dessine le level et stoque dans des evcteur de la class

    Texture charactere_texture;
    charactere_texture.loadFromFile("characters.png");  //stoque texure pour perso et ennemis

    Player hero;    // creation hero / player
    hero.update_player_position(50, 50);
    hero.update_player_texture(charactere_texture);
    hero.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
    hero.update_player_scale(3, 3);
    hero.addHeroSprite();

    Texture horseTexture;
    horseTexture.loadFromFile("horse.png");

    Horse horse;
    horse.updateHorsePosition(50, 275);
    horse.updateHorseTexture(horseTexture);
    horse.updateHorseTextureRect(IntRect(0 * 16, 0 * 16, 16 * 5, 16 * 5));
    horse.updateHorseScale(1, 1);
    horse.addHeroSprite();

    Ennemy slime;   // creation slime
    slime.update_ennemy_texture(charactere_texture);
    slime.set_tile_anim
    (
        {
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
        }
    );
    slime.update_ennemy_texture_rect(IntRect(1 * 16, 4 * 16, 16, 16));
    slime.update_ennemy_scale(3, 3);
    slime.addEnnemySprite();
    slime.set_navigation_ennemi
    (
        {
            sf::Vector2f(100, 100),
            sf::Vector2f(200, 150),
            sf::Vector2f(500, 120),
            sf::Vector2f(300, 20)
        }
    );
    slime.update_ennemy_position();

    while (window.isOpen())
    {
        manager.update_current_time();
        
        while (window.pollEvent(event))
        {
            hero.recup_event_player(event, window); // check les touche appuyé 
        }

        //deplacement et annimation player
        hero.modif_velocity_player();
        // nromalization vecteur
        
        hero.update_player_move(manager);
        hero.anim_hero(manager);

        slime.deplacement_ennemy(manager);
        slime.move();
        slime.anim_ennemy(manager);
        
        horse.mont_horse(hero, event);
        horse.dep_player_horse(hero);

        

        hero.limite_map();
        slime.move();

        vector<Sprite> recup_ground = level.recup_display_ground();
        vector<Sprite> recup_map = level.recup_display_map();

        for (int i = 0; i < recup_ground.size(); i++)
        {
            window.draw(recup_ground[i]);
        }
        for (int i = 0; i < recup_map.size(); i++)
        {
            window.draw(recup_map[i]);
        }

        window.draw(slime.recup_sprite_ennemy());
        window.draw(horse.getHorse());
        window.draw(hero.recup_hero());
        window.display();
        window.clear();
    }
    return 0;
}