#include "ennemy.h"

using namespace std;
using namespace sf;

Ennemy::Ennemy(){}

Sprite Ennemy::getEnnemySprite()
{
    return ennemy;
}

void Ennemy::addEnnemySprite()
{
    for (auto& tile : ennemyTiles)
    {
        IntRectEnnemy[tile.first] = IntRect(tile.second.x * 16, tile.second.y * 16, 16, 16);
    }
}

void Ennemy::setPath(vector<Vector2f> new_chemin)
{
    path = new_chemin;
}

void Ennemy::setEnnemyTiles(map<string, Vector2i> new_ennemy_tile)
{
    ennemyTiles = new_ennemy_tile;
}

void Ennemy::setDeath()
{
    checkDeath = true;
}

bool Ennemy::getDeath()
{
    return checkDeath;
}

void Ennemy::updateEnnemyTexture(Texture& texture)
{
    ennemy.setTexture(texture);
}

void Ennemy::updateEnnemyTextureRect(IntRect tile_ennemy)
{
    ennemy.setTextureRect(tile_ennemy);
}

void Ennemy::updateEnnemyScale(int x, int y)
{
    ennemy.setScale(x, y);
}

void Ennemy::updateEnnemyPosition()
{
    ennemy.setPosition(path[0].x, path[0].y);
}

void Ennemy::move(Manager& manager)
{
    float check_range = 3.0f;
    float distance = 0.0f;
    Vector2i dist_vecteur = { 0, 0 };
    if (index == path.size() - 1)
    {


        Vector2f pos_actu = ennemy.getPosition();
        Vector2f pos_point = path[0];
        if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= check_range && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= check_range)
        {
            if (checkCalcul == true)
            {
                ennemy.setPosition(path[0]);
                index = 0;
                checkCalcul = false;
                manager.timer_dep_ennemy = manager.clock.restart();
            }
        }
        if (checkCalcul == false && index == path.size() - 1)
        {
            checkCalcul = true;
            velocity.x = path[0].x - path[index].x;
            velocity.y = path[0].y - path[index].y;
            distance = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
            if (distance != 0)
            {
                velocity = manager.normalize(velocity, speed);
            }
            movementTimer = seconds((distance) / ((sqrt(velocity.x * velocity.x) + sqrt(velocity.y * velocity.y)) * 120));
        }
    }
    else
    {
        Vector2f pos_actu = ennemy.getPosition();
        Vector2f pos_point = path[index + 1];
        if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= check_range && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= check_range)
        {
            if (checkCalcul == true)
            {
                index += 1;
                checkCalcul = false;
                manager.timer_dep_ennemy = manager.clock.restart();
            }
        }
        if (checkCalcul == false && index < path.size() - 1)
        {
            checkCalcul = true;
            velocity.x = path[index + 1].x - path[index].x;
            velocity.y = path[index + 1].y - path[index].y;
            distance = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
            if (distance != 0)
            {
                velocity = manager.normalize(velocity, speed);

            }
        }

    }
}

void Ennemy::ennemyAnimation(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);
    if (velocity.x < 0 && velocity.y < velocity.x)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["gauche-2"]);
        }
        else if (manager.timer_slime >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["gauche-1"]);
        }
    }
    else if (velocity.y > 0 && velocity.x < velocity.y)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["bas-2"]);
        }
        else if (manager.timer_slime >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["bas-1"]);
        }
    }
    else if (velocity.x > 0 && velocity.y < velocity.x)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["droite-2"]);
        }
        else if (manager.timer_slime >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["droite-1"]);
        }
    }
    else if (velocity.y < 0 && velocity.x < velocity.y)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            ennemy.setTextureRect(IntRectEnnemy["haut-2"]);
        }
        else if (manager.timer_slime >= time2)
        {
            ennemy.setTextureRect(IntRectEnnemy["haut-1"]);
        }
    }
}