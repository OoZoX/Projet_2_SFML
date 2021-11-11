#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Manager
{
protected:


public:
	Manager();
	void update_current_time();
	sf::Time timer_player;
	sf::Time timer_slime;
	sf::Clock clock;
};

