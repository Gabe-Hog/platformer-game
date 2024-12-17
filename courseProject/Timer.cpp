#include "Timer.h"

Timer::~Timer()
{
    delete this->clock;
}

float Timer::getDeltaTime() const
{
    return this->dTime;
}

void Timer::setDeltaTime()
{
    this->dTime = this->clock->restart().asSeconds();
}

sf::Clock* Timer::getClock() const
{
    return this->clock;
}
