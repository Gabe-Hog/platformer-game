#ifndef TIMER_H
#define TIMER_H
#include "SFML/Graphics.hpp"
class Timer
{
private:
		sf::Clock* clock = new(sf::Clock);
		float dTime;
		
public:
	Timer() = default;
	~Timer();
	float getDeltaTime() const;
	void setDeltaTime();
	sf::Clock* getClock() const;
};

#endif