#include "GameObjects.h"




void GameObjects::setBounds(sf::Shape& shape)
{
	this->bounds = shape.getGlobalBounds();
}

void GameObjects::setBounds(sf::Sprite& sprite)
{
	this->bounds = sprite.getGlobalBounds();
}

sf::FloatRect GameObjects::getBounds() const
{
	return this->bounds;
}
