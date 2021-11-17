#include <SFML/Graphics.hpp>
#include "manager.h"
#include "player.h"
#include "horse.h"
#include "ennemy.h"
#include "level.h"
#include "epee.h"


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
    hero.update_player_scale(3, 3);
    hero.addHeroSprite();

    View view(FloatRect(hero.recup_position().x - 100, hero.recup_position().y - 100, 250, 250));
    window.setView(view);

    Texture horseTexture;
    horseTexture.loadFromFile("horse.png");

    Horse horse;
    horse.updateHorsePosition(50, 275);
    horse.updateHorseTexture(horseTexture);
    horse.updateHorseTextureRect(IntRect(0 * 16, 0 * 16, 16 * 5, 16* 5));
    horse.updateHorseScale(1, 1);
    horse.addHorseSprite();

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

    Epee epee("epee de base");
    Texture TextureEpee;
    
    TextureEpee.loadFromFile("epee.png");
    epee.set_placement(100, 100);
    epee.assign_texture(TextureEpee);
    epee.set_text_rect(IntRect(100, 67, 100, 67));
    epee.set_placement(100, 100);
    epee.set_scale(1, 1);


    while (window.isOpen())
    {
        manager.update_current_time();
        while (window.pollEvent(event))
        {
            horse.mont_horse(hero, event);
            if (!horse.dep_player_horse(hero))
            {
                hero.recup_event_player(event, window); // check les touche appuyé
            }
            else
            {
                horse.getHorseEvent(event, window);
            }
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        hero.modif_velocity_player();
        hero.update_player_move(manager);
        hero.anim_hero(manager);
        hero.limite_map();
        hero.checkCollision(horse, slime);

        slime.deplacement_ennemy(manager);
        slime.move();
        slime.anim_ennemy(manager);
        
        horse.updateHorseVelocity();
        horse.updateHorseMove(manager);
        horse.horseAnimation(manager, hero);
        horse.dep_player_horse(hero);
        horse.mapLimit();

        if (!horse.dep_player_horse(hero))
        {
            if (hero.recup_position().x + hero.getVelocity().x >= 0 && hero.recup_position().x + hero.getVelocity().x <= 724 && hero.recup_position().y + hero.getVelocity().y >= 0 && hero.recup_position().y + hero.getVelocity().y <= 462)
            {
                view.move(hero.getVelocity());
                window.setView(view);
            }
        }
        else
        {
            if (horse.getPosition().x + horse.getSpeed().x >= 0 && horse.getPosition().x + horse.getSpeed().x <= 716 && horse.getPosition().y + horse.getSpeed().y >= 0 && horse.getPosition().y + horse.getSpeed().y <= 462)
            {
                view.move(horse.getSpeed());
                window.setView(view);
            }
        }

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
        window.draw(epee.recup_epee());
        window.draw(slime.recup_sprite_ennemy());
        window.draw(horse.getHorse());
        window.draw(hero.recup_hero());
        window.display();
        window.clear();
    }
    return 0;
}