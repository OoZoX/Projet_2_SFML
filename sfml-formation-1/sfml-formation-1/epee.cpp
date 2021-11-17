#include "epee.h"
using namespace std;
using namespace sf;

Epee::Epee
(string new_nom)
{
	nom = new_nom;
}

void Epee::assign_texture(Texture texture)
{
	arme.setTexture(texture);
}

void Epee::set_text_rect(IntRect rect)
{
	arme.setTextureRect(rect);
}

void Epee::set_placement(int x, int y)
{
	arme.setPosition(x, y);
	cout << "place apee" << endl;
}

void Epee::set_scale(float x, float y)
{
	arme.setScale(x, y);
}

Sprite Epee::recup_epee()
{
	return arme;
}