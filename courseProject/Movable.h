#ifndef MOVABLE_H
#define MOVABLE_H

#include "SFML/Graphics.hpp"

class Movable
{
private:
	sf::Vector2f direction;
	float normalize(sf::Vector2f direction);

public:
	Movable() = default;
	Movable(Movable&) = default;
	~Movable();
	void setDirection(sf::Vector2f newDirection);
	sf::Vector2f getNormalizedDirection();
	



};


#endif

