#ifndef TIMER_H
#define TIMER_H
#include "SFML/Graphics.hpp"
class Timer
{
private:
		sf::Clock clock;
		sf::Time timer;

public:
	float getTime();
};

#endif