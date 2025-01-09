#include "Weapon.h"
#include "Character.h"


Weapon::Weapon(float speed) : speed(speed)
{
}

Weapon::Weapon(int damage, float speed) : damage(damage), speed(speed)
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

float Weapon::getSpeed() const
{
	return this->speed;
}

int Weapon::getDamage() const
{
	return this->damage;
}


void Weapon::setDidHit(bool hit)
{
	this->didHit = hit; 
}


bool Weapon::hit() const
{
	return this->didHit;
}

