#include "Movable.h"

Movable::~Movable()
{
}

void Movable::setDirection(sf::Vector2f newDirection)
{
    this->direction = newDirection;
}

sf::Vector2f Movable::getNormalizedDirection()
{
    float normalizedFactor = this->normalize(this->direction);
    sf::Vector2f normalizedDirection;
    if (normalizedFactor != 0)
        normalizedDirection = this->direction / normalizedFactor;
        
   
    return normalizedDirection;
}

float Movable::normalize(sf::Vector2f direction)
{
    return sqrt(direction.x * direction.x + direction.y * direction.y);
}
