#include "Weapon.h"
#include "Character.h"


Weapon::Weapon(int damage) : damage(damage)
{
}






void Weapon::setOwnerPosition(sf::Vector2f newOwnerPosition)
{
	this->ownerPosition = newOwnerPosition;
}

sf::Vector2f Weapon::getOwnerPosition() const
{
	return this->ownerPosition;
}

void Weapon::dealDamage(Character& character) const
{
	character.takeDamage(this->damage);
}

void Weapon::setDidHit(bool hit)
{
	this->didHit = hit; 
}


bool Weapon::hit() const
{
	return this->didHit;
}

