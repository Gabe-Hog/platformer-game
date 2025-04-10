#ifndef DIRECTIONVECTORPROCESSOR_H
#define DIRECTIONVECTORPROCESSOR_H

#include "SFML/Graphics.hpp"

class DirectionVectorProcessor
{
private:
	sf::Vector2f direction;
	float normalize(sf::Vector2f direction);

protected:

	DirectionVectorProcessor() = default;
	~DirectionVectorProcessor() = default;
	void setDirection(sf::Vector2f newDirection);
	sf::Vector2f getNormalizedDirection();

};


#endif