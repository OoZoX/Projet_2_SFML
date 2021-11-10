#include "ennemy.h"


using namespace std;
using namespace sf;

Ennemy Ennemy::ennemy(){}

Sprite Ennemy::recup_sprite_ennemy()
{
    return _ennemy;
}

void Ennemy::addEnnemySprite()
{
    for (auto& tile : ennemyTiles)
    {
        IntRectEnnemy[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }
}

void Ennemy::moveEnnemy(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);
    if (_ennemy.getPosition().x >= 266 && int(_ennemy.getPosition().y) == 0)
    {
        if (timer_slime >= time1)
        {
            timer_slime = clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["gauche-2"]);
        }

        else if (timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["gauche-1"]);
        }
    }
    else if (_ennemy.getPosition().y <= 72 && int(_ennemy.getPosition().x) == 265)
    {
        if (timer_slime >= time1)
        {
            timer_slime = clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["bas-2"]);
        }

        else if (timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["bas-1"]);
        }
    }
    else if (_ennemy.getPosition().x <= 330 && int(_ennemy.getPosition().y) == 73)
    {
        if (timer_slime >= time1)
        {
            timer_slime = clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["droite-2"]);
        }

        else if (timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["droite-1"]);
        }
    }
    else if (_ennemy.getPosition().y >= 0 && int(_ennemy.getPosition().x) == 331)
    {
        if (timer_slime >= time1)
        {
            timer_slime = clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["haut-2"]);
        }

        else if (timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["haut-1"]);
        }
    }

}

void Ennemy::move()
{
    if (_ennemy.getPosition().x >= 266 && int(_ennemy.getPosition().y) == 0)
    {
        _ennemy.move(-1, 0);
    }
    else if (_ennemy.getPosition().y <= 72 && int(_ennemy.getPosition().x) == 265)
    {
        _ennemy.move(0, 1);
    }
    else if (_ennemy.getPosition().x <= 330 && int(_ennemy.getPosition().y) == 73)
    {
        _ennemy.move(1, 0);
    }
    else if (_ennemy.getPosition().y >= 0 && int(_ennemy.getPosition().x) == 331)
    {
        _ennemy.move(0, -1);
    }
}

void Ennemy::update_ennemy_texture(Texture texture)
{
    _ennemy.setTexture(texture);
}

void Ennemy::update_ennemy_texture_rect(IntRect tile_ennemy)
{
    _ennemy.setTextureRect(tile_ennemy);
}

void Ennemy::update_ennemy_scale(int x, int y)
{
    _ennemy.setScale(x, y);
}

void Ennemy::update_ennemy_position(int x, int y)
{
    _ennemy.setPosition(x, y);
}