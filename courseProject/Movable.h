#ifndef MOVABLE_H
#define MOVABLE_H

#include "GameObjects.h"
class Movable : public GameObjects
{
private:
	sf::Vector2f direction;
	float normalize(sf::Vector2f direction);

public:
	Movable() = default;
	~Movable();
	virtual void updatePosition(float dTime) = 0;
	void setDirection(sf::Vector2f newDirection);
	sf::Vector2f getNormalizedDirection();
	



};


#endif

