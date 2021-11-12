#include <SFML/Graphics.hpp>
#include "manager.h"
#include "player.h"
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

    RenderWindow window(VideoMode(1500, 1000), "SFML works!");    //768, 512
    window.setKeyRepeatEnabled(false);
    window.setFramerateLimit(60);

    Manager manager;    // creation manager

    Level level;    //creation map 
    Texture mapTexture;
    mapTexture.loadFromFile("foresttiles2-t.png");     // set la texture 
    level.displayLevel(mapTexture); // dessine le level et staoque dans des evcteur de la class

    Texture charactere_texture;
    charactere_texture.loadFromFile("characters.png");

    Player hero;    // creation hero / player
    hero.update_player_position(50, 50);
    hero.update_player_texture(charactere_texture);
    hero.update_player_texture_rect(IntRect(1 * 16, 0 * 16, 16, 16));
    hero.update_player_scale(3, 3);
    hero.addHeroSprite();

    Ennemy slime;   // creation slime
    slime.update_ennemy_texture(charactere_texture);
    slime.update_ennemy_texture_rect(IntRect(1 * 16, 4 * 16, 16, 16));
    slime.update_ennemy_scale(3, 3);
    slime.update_ennemy_position();
    slime.addEnnemySprite();

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
        slime.moveEnnemy(manager);

        

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
        window.draw(hero.recup_hero());
        window.display();
        window.clear();
    }
    return 0;
}