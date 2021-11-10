#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Manager
{
protected:
	sf::Clock clock;
	sf::Time timer;

	

public:
	Manager manager();
	void update_current_time();
};

