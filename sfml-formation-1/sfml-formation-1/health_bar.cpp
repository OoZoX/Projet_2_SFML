#include "health_bar.h"
HealthBar::HealthBar(){}

using namespace sf;
using namespace std;

void HealthBar::set_position(Vector2f pos)
{
	bar.setPosition(pos.x -3 , pos.y -10);
}

void HealthBar::set_bar()
{
	bar.setSize(Vector2f(50, 7));
	bar.setFillColor(Color(255, 0, 0));
}

RectangleShape HealthBar::get_bar()
{
	return bar;
}

void HealthBar::chang_vie()
{

	vie -= 20;
	if (vie < 0)
	{
		vie = 0;
	}
	chang_size_bar();

}

void HealthBar::chang_size_bar()
{
	float size = (vie * 50) / 100;
	bar.setSize(Vector2f(size, 7));
}

int HealthBar::get_vie()
{
	return vie;
}