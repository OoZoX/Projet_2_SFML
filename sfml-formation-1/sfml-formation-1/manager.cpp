#include "manager.h"

using namespace sf;
using namespace std;

Manager::Manager(){};

void Manager::update_current_time()
{
    timer_player = clock.getElapsedTime();
    timer_slime = clock.getElapsedTime();
    timer_dep_ennemy = clock.getElapsedTime();

}

Vector2f Manager::normalize(Vector2f velocity, float speed)
{

    float norme = sqrt((velocity.x * velocity.x) + (velocity.y * velocity.y));

    if (norme != 0)
    {
        velocity = ((velocity) / norme) * speed;
    }

    return velocity;
}