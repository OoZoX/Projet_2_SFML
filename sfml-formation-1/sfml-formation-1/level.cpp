#include "level.h"

using namespace std;
using namespace sf;

typedef Vector2i vec2i;


void Level::displayLevel(Texture& texture) {

    const int size = 16;
    const int scale = 4;

    for (int i = 0; i < tile_strings.size(); i++)
    {
        string ligne = tile_strings[i];
        for (int u = 0; u < ligne.size() / 3; u++)
        {

            string lettres = ligne.substr(u * 3, 2);
            if (aliasses.count(lettres) || lettres == "  ")
            {
                string recup_key1 = aliasses[lettres];
                if (tile_offsets.count(recup_key1) || lettres == "  ")
                {
                    vec2i position = tile_offsets[recup_key1];

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
}

vector<Sprite> Level::recup_display_map()
{
    return displayMap;
}

vector<Sprite> Level::recup_display_ground()
{
    return displayGround;
}

