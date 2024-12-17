#include "Character.h"

Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed) : wep(weapon), health(newHealth), moveSpeed(newMoveSpeed)
{
}

Character::~Character()
{
	delete this->wep;
}

void Character::setBounds(const sf::Shape& shape)
{
	this->bounds = shape.getGlobalBounds();
}

sf::FloatRect Character::getBounds()
{
	return this->bounds;
}



float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}

void Character::calcHealth() 
{
}
