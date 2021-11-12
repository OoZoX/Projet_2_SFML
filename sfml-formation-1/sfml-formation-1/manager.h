#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Manager
{
protected:


public:
	sf::Time timer_player;
	sf::Time timer_slime;
	sf::Time timer_dep_ennemy;
	sf::Clock clock;

	Manager();
	void update_current_time();
	sf::Vector2f normalize(sf::Vector2f, float);


};

