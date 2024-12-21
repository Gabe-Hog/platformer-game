#include "GameObjects.h"

GameObjects::~GameObjects()
{
	
}

void GameObjects::setBounds(sf::Shape& shape)
{
	this->bounds = shape.getGlobalBounds();
}

sf::FloatRect GameObjects::getBounds() const
{
	return this->bounds;
}
