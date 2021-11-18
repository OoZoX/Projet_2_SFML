#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Player;
class Ennemy;

class Epee
{
	int attaque = 10;
	std::string nom;
	sf::Sprite arme;

public:
	Epee(std::string);
	void assign_texture(sf::Texture&);
	void set_text_rect(sf::IntRect);
	void set_placement(int, int);
	void set_scale(float x , float y);
	sf::Sprite recup_epee();
	void set_rotate(int rota);
	int get_rotate();
	void set_origine(int x, int y);
	void check_colis_epee(Ennemy& ennemy, Player& player);
};

