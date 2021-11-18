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

void Ennemy::anim_ennemy(Manager& manager)
{
    Time time1 = seconds(0.5f);
    Time time2 = seconds(0.25f);


    if (velocity.x < 0 && velocity.y < velocity.x)
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
    else if (velocity.y > 0 && velocity.x < velocity.y)
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
    else if (velocity.x > 0 && velocity.y < velocity.x)
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
    else if (velocity.y < 0 && velocity.x < velocity.y)
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
    float check_range = 3.0f;
    float distance = 0.0f;
    Vector2i dist_vecteur = { 0, 0 };
    // Pour le temps -> manager.timer_dep_ennemy

        if (index == chemin.size()-1)
        {
            
            
            Vector2f pos_actu = _ennemy.getPosition();
            Vector2f pos_point = chemin[0];
            if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= check_range && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= check_range)
            {
                if (check_calcul == true)
                {
                    _ennemy.setPosition(chemin[0]);
                    cout << _ennemy.getPosition().x << endl;
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
            if (sqrt((pos_point.x - pos_actu.x) * (pos_point.x - pos_actu.x)) <= check_range && sqrt((pos_point.y - pos_actu.y) * (pos_point.y - pos_actu.y)) <= check_range)
            {
                if (check_calcul == true)
                {
                    cout << _ennemy.getPosition().x << endl;
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

void Ennemy::set_navigation_ennemi(vector<Vector2f> new_chemin)
{
    chemin = new_chemin;
}

void Ennemy::set_tile_anim(map<string, Vector2i> new_ennemy_tile)
{
    ennemyTiles = new_ennemy_tile;
}

void Ennemy::set_mort()
{
    check_mort = true;
}

bool Ennemy::get_mort()
{
    return check_mort;
}