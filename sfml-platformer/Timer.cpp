#include "Timer.h"
#include <math.h>
Timer::~Timer()
{
    delete this->clock;
}

void Timer::addToElapsedTime(float timeElapsed)
{
    this->elapsedTime += timeElapsed;
}


float Timer::getDeltaTime() const
{
    return this->dTime;
}

float Timer::getTimerElapsedTime() const
{
    return round(this->elapsedTime*100.0)/100.0;
}

void Timer::setDeltaTime()
{
    this->dTime = this->clock->restart().asSeconds();
}

sf::Clock* Timer::getClock() const
{
    return this->clock;
}
