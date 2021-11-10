#include "manager.h"

using namespace sf;
using namespace std;

Manager Manager::manager() {};

void Manager::update_current_time()
{
    timer = clock.getElapsedTime();
}