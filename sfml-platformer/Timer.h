#ifndef TIMER_H
#define TIMER_H
#include "SFML/Graphics.hpp"
class Timer
{
private:
		sf::Clock* clock = new(sf::Clock);
		float dTime = 0.f;
		float elapsedTime = 0.f;
		
public:
	Timer() = default;
	~Timer();
	void addToElapsedTime(float elapsedTime);
	float getDeltaTime() const;
	float getTimerElapsedTime() const;
	void setDeltaTime();
	sf::Clock* getClock() const;
};

#endif