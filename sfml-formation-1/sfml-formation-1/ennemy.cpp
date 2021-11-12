#include "ennemy.h"


using namespace std;
using namespace sf;

Ennemy::Ennemy(){}

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
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["gauche-2"]);
        }

        else if (manager.timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["gauche-1"]);
        }
    }
    else if (_ennemy.getPosition().y <= 72 && int(_ennemy.getPosition().x) == 265)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["bas-2"]);
        }

        else if (manager.timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["bas-1"]);
        }
    }
    else if (_ennemy.getPosition().x <= 330 && int(_ennemy.getPosition().y) == 73)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["droite-2"]);
        }

        else if (manager.timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["droite-1"]);
        }
    }
    else if (_ennemy.getPosition().y >= 0 && int(_ennemy.getPosition().x) == 331)
    {
        if (manager.timer_slime >= time1)
        {
            manager.timer_slime = manager.clock.restart();
            _ennemy.setTextureRect(IntRectEnnemy["haut-2"]);
        }

        else if (manager.timer_slime >= time2)
        {
            _ennemy.setTextureRect(IntRectEnnemy["haut-1"]);
        }
    }
}


void Ennemy::move()
{
    _ennemy.move(velocity);
    

    /*
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
    }   */
}

void Ennemy::update_ennemy_texture(Texture& texture)
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

void Ennemy::update_ennemy_position()
{
    _ennemy.setPosition(chemin[0].x, chemin[0].y);
}

void Ennemy::deplacement_ennemy(Manager& manager)
{
    float distance = 0.0f;
    Vector2i dist_vecteur = { 0, 0 };
    // Pour le temps -> manager.timer_dep_ennemy

        if (index == chemin.size()-1)
        {
            
            
            Vector2f pos_actu = _ennemy.getPosition();
            Vector2f pos_point = chemin[0];
            if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= 4.0f && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= 4.0f)
            {


                if (check_calcul == true)
                {
                    _ennemy.setPosition(chemin[0]);
                    index = 0;
                    check_calcul = false;
                    manager.timer_dep_ennemy = manager.clock.restart();
                }
            }
            if (check_calcul == false && index == chemin.size()-1) 
            {
                cout << "index " << index << endl;
                check_calcul = true;

                //recup dist entre les vecteur
                velocity.x = chemin[0].x - chemin[index].x;
                velocity.y = chemin[0].y - chemin[index].y;

                // recup dist entre les points avec Phytagore 
                distance = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
                if (distance != 0)
                {
                    velocity = manager.normalize(velocity, speed);
                }
               
                /*
                distance = sqrt((dist_vecteur.x * dist_vecteur.x) - (dist_vecteur.y * dist_vecteur.y));

                velocity.x = ((dist_vecteur.x / distance) * speed);
                velocity.y = ((dist_vecteur.y / distance) * speed);
                */
                timer_deplacement = seconds((distance) / ((sqrt(velocity.x * velocity.x) + sqrt(velocity.y * velocity.y)) * 120));

                cout << "distance " << distance << endl;
                cout << "timer deplacement ennemy " << timer_deplacement.asSeconds() << endl;
            }
        }
        else
        {
            
            Vector2f pos_actu = _ennemy.getPosition();
            Vector2f pos_point = chemin[index +1];
            if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= 4.0f && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= 4.0f)
            {
            
            if (check_calcul == true)
            {
                index += 1;
                check_calcul = false;
                manager.timer_dep_ennemy = manager.clock.restart();
            }
            }
            if (check_calcul == false && index < chemin.size()-1)
            {
                check_calcul = true;
                //recup dist entre les vecteur
                cout << "index " << index << "//////////////////" << endl;
                velocity.x = chemin[index + 1].x - chemin[index].x;
                velocity.y = chemin[index + 1].y - chemin[index].y;

                // recup dist entre les points avec Phytagore 
                distance = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));
                if (distance != 0)
                {
                    velocity = manager.normalize(velocity, speed);

                }
                
                /*
                distance = sqrt((dist_vecteur.x * dist_vecteur.x) - (dist_vecteur.y * dist_vecteur.y));

                velocity.x = ((dist_vecteur.x / distance) * speed);
                velocity.y = ((dist_vecteur.y / distance) * speed);
                */
            }

        }
    
}