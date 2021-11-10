#include <SFML/Graphics.hpp>
#include "manager.h"
#include "player.h"
#include "ennemy.h"
#include "level.h"


#include <map>
#include <iostream>

typedef Vector2f vec2;
typedef Vector2i vec2i;

using namespace sf;
using namespace std;


void moveEnnemy(sf::Time& timer, Clock& clock, Sprite& ennemy, map<string, IntRect>& IntRectEnnemy)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);
    if (ennemy.getPosition().x >= 266 && int(ennemy.getPosition().y) == 0)
    {
        if (timer >= time1)
        {
            timer = clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["gauche-2"]);
        }

        else if (timer >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["gauche-1"]);
        }
    }
    else if (ennemy.getPosition().y <= 72 && int(ennemy.getPosition().x) == 265)
    {
        if (timer >= time1)
        {
            timer = clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["bas-2"]);
        }

        else if (timer >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["bas-1"]);
        }
    }
    else if (ennemy.getPosition().x <= 330 && int(ennemy.getPosition().y) == 73)
    {
        if (timer >= time1)
        {
            timer = clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["droite-2"]);
        }

        else if (timer >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["droite-1"]);
        }
    }
    else if (ennemy.getPosition().y >= 0 && int(ennemy.getPosition().x) == 331)
    {
        if (timer >= time1)
        {
            timer = clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["haut-2"]);
        }

        else if (timer >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["haut-1"]);
        }
    }
    
}


int main()
{
    // lancement des class //
    RenderWindow window(VideoMode(768, 512), "SFML works!");
    Manager manager;
    Player hero;

    Texture mapTexture;
    mapTexture.loadFromFile("foresttiles2-t.png");
    vector<vector<Sprite>> recup_map = displayLevel(mapTexture);

    Texture charactersTexture;
    charactersTexture.loadFromFile("characters.png");

    Sprite hero;
    hero.setPosition(50, 50);
    hero.setTexture(charactersTexture);
    hero.setTextureRect(IntRect(1 * 16, 0 * 16, 16, 16));
    hero.setScale(3, 3);
    hero.setPosition(50, 50);
    map<string, IntRect> IntRectPerso = addHeroSprite();
    sf::Vector2f velocity;
    float speed = 2.0f;

    Sprite slime;
    slime.setTexture(charactersTexture);
    slime.setTextureRect(IntRect(1 * 16, 4 * 16, 16, 16));
    slime.setScale(3, 3);
    slime.setPosition(330, 0);
    map<string, IntRect> IntRectEnnemy = addEnnemySprite();

    Clock clock;
    Time timer;
    Time mesureTemp = seconds(0.1f);

    window.setFramerateLimit(60);

    sf::Event event;

    while (window.isOpen())
    {
        timer = clock.getElapsedTime();
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W)
                {
                    activeKeys[UP] = true;
                }
                else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A)
                {
                    activeKeys[LEFT] = true;
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    activeKeys[DOWN] = true;
                }
                else if (event.key.code == sf::Keyboard::D)
                {
                    activeKeys[RIGHT] = true;
                }

            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Z || event.key.code == sf::Keyboard::W) 
                { 
                    activeKeys[UP] = false; 
                }
                else if (event.key.code == sf::Keyboard::Q || event.key.code == sf::Keyboard::A) 
                { 
                    activeKeys[LEFT] = false; 
                }
                else if (event.key.code == sf::Keyboard::S) 
                { 
                    activeKeys[DOWN] = false; 
                }
                else if (event.key.code == sf::Keyboard::D) 
                { 
                    activeKeys[RIGHT] = false; 
                }
            }
        }

        for (int i = 0; i < recup_map[1].size(); i++)
        {
            window.draw(recup_map[1][i]);
        }
        for (int i = 0; i < recup_map[0].size(); i++)
        {
            window.draw(recup_map[0][i]);
        }

        normalize(velocity, speed);
        hero.move(velocity);
        moveHero(timer, clock, velocity, hero, IntRectPerso, exKey);
        moveEnnemy(timer, clock, slime, IntRectEnnemy);

        if (activeKeys[UP] == false) { velocity.y -= velocity.y; }
        if (activeKeys[LEFT] == false) { velocity.x -= velocity.x; }
        if (activeKeys[RIGHT] == false) { velocity.x -= velocity.x; }
        if (activeKeys[DOWN] == false) { velocity.y -= velocity.y; }
        if (activeKeys[UP]) { velocity.y -= speed; }
        if (activeKeys[LEFT]) {velocity.x -= speed; }
        if (activeKeys[RIGHT]) { velocity.x += speed; }
        if (activeKeys[DOWN]) { velocity.y += speed; }

        if (hero.getPosition().x <= 0)
        {
            hero.setPosition(0, hero.getPosition().y);
        }
        else if (hero.getPosition().x >= 720)
        {
            hero.setPosition(720, hero.getPosition().y);
        }
        else if (hero.getPosition().y <= 0) 
        {
            hero.setPosition(hero.getPosition().x, 0);
        }
        else if (hero.getPosition().y >= 464) 
        {
            hero.setPosition(hero.getPosition().x, 464);
        }

        if (slime.getPosition().x >= 266 && int(slime.getPosition().y) == 0)
        {
            slime.move(-1, 0);
        }
        else if (slime.getPosition().y <= 72 && int(slime.getPosition().x) == 265)
        {
            slime.move(0, 1);
        }
        else if (slime.getPosition().x <= 330 && int(slime.getPosition().y) == 73)
        {
            slime.move(1, 0);
        }
        else if (slime.getPosition().y >= 0 && int(slime.getPosition().x) == 331)
        {
            slime.move(0, -1);
        }

        window.draw(slime);
        window.draw(hero);
        window.display();
        window.clear();
    }
    return 0;
}