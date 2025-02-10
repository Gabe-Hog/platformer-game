#include "DirectionVectorProcessor.h"


void DirectionVectorProcessor::setDirection(sf::Vector2f newDirection)
{
    this->direction = newDirection;
}

sf::Vector2f DirectionVectorProcessor::getNormalizedDirection()
{
    float normalizedFactor = this->normalize(this->direction);
    sf::Vector2f normalizedDirection;
    if (normalizedFactor != 0)
        normalizedDirection = this->direction / normalizedFactor;
        
   
    return normalizedDirection;
}

float DirectionVectorProcessor::normalize(sf::Vector2f direction)
{
    return sqrt(direction.x * direction.x + direction.y * direction.y);
}
