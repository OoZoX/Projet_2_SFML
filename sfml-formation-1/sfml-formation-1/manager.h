#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Manager
{
protected:
	sf::Clock clock;


	

public:
	Manager manager();
	void update_current_time();
	sf::Time timer_player;
	sf::Time timer_slime;
};

