#pragma once
#include <SFML/Graphics.hpp>
class HealthBar
{
	int vie = 100;
	sf::Sprite coeur;
	sf::RectangleShape bar;

public:
	HealthBar();

	void set_position(sf::Vector2f position);

	void set_texture(sf::Texture& texture);

	void set_bar();

	sf::Sprite get_coeur();

	sf::RectangleShape get_bar();

	void chang_vie();

	void chang_size_bar();

	int get_vie();

};

