#pragma once
#include <SFML/Graphics.hpp>
class HealthBar
{
	int vie = 100;
	sf::RectangleShape bar;

public:
	HealthBar();

	void set_position(sf::Vector2f position);

	void set_bar();

	sf::RectangleShape get_bar();

	void chang_vie();

	void chang_size_bar();

	int get_vie();

};

