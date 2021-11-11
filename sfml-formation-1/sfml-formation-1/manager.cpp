#include "manager.h"

using namespace sf;
using namespace std;

Manager::Manager(){};

void Manager::update_current_time()
{
    timer_player = clock.getElapsedTime();
    timer_slime = clock.getElapsedTime();
    cout << "___________" << timer_player.asSeconds() << endl;
    cout << "///////////" << timer_slime.asSeconds() << endl;

}