#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
class Epee
{
	int attaque = 10;
	std::string nom;
	sf::Sprite arme;

public:
	Epee(std::string);
	void assign_texture(sf::Texture);
	void set_text_rect(sf::IntRect);
	void set_placement(int, int);
	void set_scale(float, float);
	sf::Sprite recup_epee();
};

