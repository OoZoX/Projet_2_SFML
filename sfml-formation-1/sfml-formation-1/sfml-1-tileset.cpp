#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include <map>
#include <iostream>
typedef Vector2f vec2;
typedef Vector2i vec2i;
/*
Dans cet example, vous allez devoir charger et afficher un tileset
Vous devrez charger plusieurs sprites, de préférences dans un vector<>.
Vous devrez utiliser la fonction Sprite::setTextureRect() qui prend un IntRect en argument.

Un IntRect est un struct POD (plain old data type) contenant une origine et une taille, en entier.

Cette fonction permet de n'afficher que une certaine région de texture dans votre Sprite.

Je vous ai fourni un niveau à charger, une std::map<string,string> et une std::map<string, Vector2i> préremplies, et une image qui permet de visualiser la disposition des tiles.

Votre travail consiste à écrire la fonction load_level(), qui doit:
* instancier les Sprite et appeler la fonction setTextureRect() sur chacun d'entre eux.
* positionner les Sprites
Les tiles font 16x16px, il faudra donc multiplier par 16 les offset fournis dans la map
Il sera nécessaire de charger deux grilles de tiles, la première étant celle du sol, et l'autre des objets.

*/

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


vector<vector<Sprite>> display_map(Texture& texture) {
    vector<Sprite> aff_map;
    vector<Sprite> aff_sol;
    const int multi_size = 16;
    const int val_scale = 4;
    
    for (int i = 0; i < level::tile_strings.size(); i++)
    {
        string ligne = level::tile_strings[i];
        for (int u = 0; u < ligne.size() /3; u++)
        {

            string lettres = ligne.substr(u*3, 2);
            if (level::aliasses.count(lettres) || lettres == "  ")
            {
                string recup_key1 = level::aliasses[lettres];
                if (level::tile_offsets.count(recup_key1)|| lettres == "  ")
                {
                    vec2i position = level::tile_offsets[recup_key1];

                    Sprite sprite;

                    Sprite sol;

                    
                    sol.setTexture(texture);
                    sol.setTextureRect(IntRect(4 * multi_size, 6 * multi_size, multi_size, multi_size));
                    sol.setPosition(u * multi_size * val_scale, i * multi_size * val_scale);
                    sol.setScale(val_scale, val_scale);
                    aff_sol.push_back(sol);

                    if (lettres != "  ")
                    {
                        sprite.setTexture(texture);
                        sprite.setTextureRect(IntRect(position.x * multi_size, position.y * multi_size, multi_size, multi_size));
                        sprite.setPosition(u * multi_size * val_scale, i * multi_size * val_scale);
                        sprite.setScale(val_scale, val_scale);
                        aff_map.push_back(sprite);
                    }

                }
                else 
                {
                    cout << "Erreur Key 2 !!! ---------------- \n";
                }
            }
            else
            {
                cout << "Erreur Key 1 !!! ---------------- \n";
            }


        }


    }

    return {aff_map, aff_sol};

}
int main()
{
    Texture texture;
    texture.loadFromFile("foresttiles2-t.png");
    sf::RenderWindow window(sf::VideoMode(768, 512), "SFML works!");
    vector<vector<Sprite>> recup_map = display_map(texture);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        


        for (int i = 0; i < recup_map[1].size(); i++)
        {
            window.draw(recup_map[1][i]);
        }
        for (int i = 0; i < recup_map[0].size(); i++)
        {
            window.draw(recup_map[0][i]);
        }
        window.display();
        window.clear();
        }

        

    return 0;
}