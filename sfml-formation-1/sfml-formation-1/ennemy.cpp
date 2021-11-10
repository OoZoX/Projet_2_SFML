#include "ennemy.h"

using namespace std;
using namespace sf;

void Ennemy::addEnnemySprite()
{
    map<string, IntRect> local_IntRectEnnemy;

    for (auto& tile : ennemyTiles)
    {
        local_IntRectEnnemy[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }

    IntRectEnnemy = local_IntRectEnnemy;
}