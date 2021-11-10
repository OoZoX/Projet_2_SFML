#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include <map>
#include <iostream>
typedef Vector2f vec2;
typedef Vector2i vec2i;

namespace level {
    map<string, vec2i> tile_offsets = {
        { "convex_angle1", {0,0}},    //
        { "convex_angle2", {1,0}},    //

        { "convex_side1", {0,1}},     //
        { "convex_side2", {1,1}},     //

        { "convex_angle3", {0,2}},    //
        { "convex_angle4", {1,2}},    //


        { "forest_NW", {2,0}},        //
        { "forest_N", {3,0}},         //
        { "forest_NE", {4,0}},        //

        { "forest_W", {2,1}},         //
        { "forest_C", {3,1}},         //
        { "forest_E", {4,1}},         //

        { "forest_SW", {2,2}},        //
        { "forest_S", {3,2}},         //
        { "forest_SE", {4,2}},        //

        { "forest_S2", {0,5}},        //


        { "tree_big_1", {0,3}},       //
        { "tree_big_2", {1,3}},       //
        { "tree_big_3", {0,4}},       //
        { "tree_big_4", {1,4}},       //


        { "stump1", {2,3}},           //
        { "stump2", {2,4}},           //
        { "flowers", {3,3}},          //
        { "grass", {1,5}},            //

        { "ground", {4,6}},           //

        { "pool", {3,3}},  //
        { "river_corner_BL", {1,6}},  //
        { "river_corner_BR", {0,6}},  //

        { "river_corner_TR", {2,6}},  //
        { "river_corner_TL", {3,6}},  //

        { "river_vert", {2,5}},       //
        { "river_horiz", {3,5}},      //


        { "tree_base", {4,5}},        //
        { "tree_middle", {4,4}},      //
        { "tree_top", {4,3}},         //
        { "nothing", {0,7}},
    };
    map<string, string> aliasses = {

        { "A1", "convex_angle1" },
        { "A2", "convex_angle2" },

        { "S1", "convex_side1" },
        { "S2", "convex_side2" },

        { "A3", "convex_angle3" },
        { "A4", "convex_angle4" },


        { "F1", "forest_NW" },
        { "FN", "forest_N" },
        { "F2", "forest_NE" },

        { "FW", "forest_W" },
        { "FC", "forest_C" },
        { "FE", "forest_E" },

        { "F7", "forest_SW" },
        { "FS", "forest_S" },
        { "F4", "forest_SE" },

        { "FZ", "forest_S2" },


        { "T1", "tree_big_1" },
        { "T2", "tree_big_2" },
        { "T3", "tree_big_3" },
        { "T4", "tree_big_4" },


        { "d1", "stump1" },
        { "d2", "stump2" },
        { "FL", "flowers" },
        { "GS", "grass" },

        { "GD", "ground" },
        { "PL", "pool" },

        { "R2", "river_corner_BL" },
        { "R1", "river_corner_BR" },

        { "R3", "river_corner_TR" },
        { "R4", "river_corner_TL" },

        { "RH", "river_horiz" },
        { "RV", "river_vert" },


        { "tb", "tree_base" },
        { "tm", "tree_middle" },
        { "tt", "tree_top" },
        { "--", "nothing" },

    };
    vector<string> tile_strings = {
        "   GS GS                FW FC A2 -- ",
        "      GS GS       tt    F7 FS S2 -- ",
        "                  tb    tt    FW FC ",
        "   T1 T2    FL          tm    F7 FS ",
        "   T3 T4          GS    tb    F1 FN ",
        "                     F1 FN FN A4 -- ",
        "      R1 R2    F1 FN A4 -- -- -- -- ",
        "R1 RH R4 R3 R2 FW -- -- -- -- -- -- ",

    };
}

vector<vector<Sprite>> displayLevel(Texture& texture) {
    vector<Sprite> displayMap;
    vector<Sprite> displayGround;
    const int size = 16;
    const int scale = 4;

    for (int i = 0; i < level::tile_strings.size(); i++)
    {
        string ligne = level::tile_strings[i];
        for (int u = 0; u < ligne.size() / 3; u++)
        {

            string lettres = ligne.substr(u * 3, 2);
            if (level::aliasses.count(lettres) || lettres == "  ")
            {
                string recup_key1 = level::aliasses[lettres];
                if (level::tile_offsets.count(recup_key1) || lettres == "  ")
                {
                    vec2i position = level::tile_offsets[recup_key1];

                    Sprite sprite;

                    Sprite ground;


                    ground.setTexture(texture);
                    ground.setTextureRect(IntRect(4 * size, 6 * size, size, size));
                    ground.setPosition(u * size * scale, i * size * scale);
                    ground.setScale(scale, scale);
                    displayGround.push_back(ground);

                    if (lettres != "  ")
                    {
                        sprite.setTexture(texture);
                        sprite.setTextureRect(IntRect(position.x * size, position.y * size, size, size));
                        sprite.setPosition(u * size * scale, i * size * scale);
                        sprite.setScale(scale, scale);
                        displayMap.push_back(sprite);
                    }

                }
            }
        }
    }

    return { displayMap, displayGround };

}

void normalize(Vector2f& velocity, float speed)
{

    float norme = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
    if (norme != 0)
    {
        velocity.x = ((velocity.x) / norme) * speed;
        velocity.y = ((velocity.y) / norme) * speed;
    }

}

map<string, vec2i> heroTiles = {
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


map<string, IntRect> addHeroSprite()
{
    map<string, IntRect> IntRectHero;

    for (auto & tile : heroTiles)
    {
        IntRectHero[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }

    return IntRectHero;
}

enum Keys { UP, DOWN, LEFT, RIGHT, SPACE, KEY_MAX };
bool activeKeys[KEY_MAX] = { false };


void moveHero(sf::Time& timer, Clock& clock, Vector2f velocity, Sprite& hero, map<string, IntRect>& IntRectHero, Keys& exKey)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);

    if (activeKeys[DOWN])
    {
        exKey = Keys::DOWN;
        if (velocity.y > 0) 
        {
            if (timer >= time1)
            {
                timer = clock.restart();

                hero.setTextureRect(IntRectHero["bas-2"]);
            }

            else if (timer >= time2)
            {
                hero.setTextureRect(IntRectHero["bas-1"]);
            }
        }
        
    }
    else if (activeKeys[UP])
    {
        exKey = Keys::UP;
        if (velocity.y < 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                hero.setTextureRect(IntRectHero["haut-2"]);
            }

            else if (timer >= time2)
            {
                hero.setTextureRect(IntRectHero["haut-1"]);
            }
        }


    }
    else if (activeKeys[RIGHT])
    {
        exKey = Keys::RIGHT;
        if (velocity.x > 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                hero.setTextureRect(IntRectHero["droite-2"]);
            }

            else if (timer >= time2)
            {
                hero.setTextureRect(IntRectHero["droite-1"]);
            }
        }


    }
    else if (activeKeys[LEFT])
    {
        exKey = Keys::LEFT;
        if (velocity.x < 0)
        {
            if (timer >= time1)
            {
                timer = clock.restart();
                hero.setTextureRect(IntRectHero["gauche-2"]);
            }

            else if (timer >= time2)
            {
                hero.setTextureRect(IntRectHero["gauche-1"]);
            }
        }

    }
    else if (exKey == Keys::DOWN)
    {
        hero.setTextureRect(IntRectHero["bas"]);
    }
    else if (exKey == Keys::UP)
    {
        hero.setTextureRect(IntRectHero["haut"]);
    }
    else if (exKey == Keys::RIGHT)
    {
        hero.setTextureRect(IntRectHero["droite"]);
    }
    else if (exKey == Keys::LEFT)
    {
        hero.setTextureRect(IntRectHero["gauche"]);
    }
}

map<string, vec2i> ennemyTiles = {
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
};

map<string, IntRect> addEnnemySprite()
{
    map<string, IntRect> IntRectEnnemy;

    for (auto& tile : ennemyTiles)
    {
        IntRectEnnemy[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }

    return IntRectEnnemy;
}

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
    sf::RenderWindow window(sf::VideoMode(768, 512), "SFML works!");

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
    Keys exKey = Keys::DOWN;
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