#include "epee.h"
#include "player.h"

using namespace std;
using namespace sf;

Epee::Epee
(string new_nom)
{
	nom = new_nom;
}

void Epee::assign_texture(Texture& texture)
{
	arme.setTexture(texture);
	cout << "texture" << endl;
}

void Epee::set_text_rect(IntRect rect)
{
	arme.setTextureRect(rect);
	cout << "rect" << endl;
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

void Epee::set_rotate(int rota)
{
	arme.setRotation(rota);
}

int Epee::get_rotate()
{
	return arme.getRotation();
}

void Epee::set_origine(int x, int y)
{
	arme.setOrigin(x, y);
}