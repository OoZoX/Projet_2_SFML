#include "epee.h"
#include "player.h"
#include "ennemy.h"

using namespace std;
using namespace sf;

Weapon::Weapon(string new_nom)
{
	name = new_nom;
}

Sprite Weapon::getWeapon()
{
	return weapon;
}

void Weapon::setWeaponTexture(Texture& texture)
{
	weapon.setTexture(texture);
}

void Weapon::setWeaponTextureRect(IntRect rect)
{
	weapon.setTextureRect(rect);

}

void Weapon::setWeaponPosition(int x, int y)
{
	weapon.setPosition(x, y);

}

void Weapon::setWeaponScale(float x, float y)
{
	weapon.setScale(x, y);
}

void Weapon::setWeaponOrigin(int x, int y)
{
	weapon.setOrigin(x, y);
}

void Weapon::setWeaponRotate(int rota)
{
	weapon.setRotation(rota);
}

int Weapon::getWeaponRotate()
{
	return weapon.getRotation();
}

void Weapon::checkWeaponCollision(Ennemy& ennemy, Player& player)
{
	Sprite ennemySprite = ennemy.getEnnemySprite();
	if (weapon.getGlobalBounds().intersects(ennemySprite.getGlobalBounds()))
	{
		if (player.recup_attaque())
		{
			ennemy.setDeath();
		}
	}
}

