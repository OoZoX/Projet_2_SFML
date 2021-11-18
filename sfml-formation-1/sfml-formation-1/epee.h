#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player;
class Ennemy;

class Weapon
{
	int attack = 10;
	std::string name;
	sf::Sprite weapon;

public:
	Weapon(std::string);
	sf::Sprite getWeapon();
	void setWeaponTexture(sf::Texture&);
	void setWeaponTextureRect(sf::IntRect);
	void setWeaponPosition(int, int);
	void setWeaponScale(float x , float y);
	void setWeaponOrigin(int x, int y);
	void setWeaponRotate(int rota);
	int	 getWeaponRotate();
	void checkWeaponCollision(Ennemy& ennemy, Player& player);
};

