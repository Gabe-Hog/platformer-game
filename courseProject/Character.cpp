#include "Character.h"
#include "Weapon.h"
#include <iostream>
Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed) :
	wep(weapon), health(newHealth), moveSpeed(newMoveSpeed)
{

}

Character::~Character()
{
	delete this->wep;
}

//void Character::setBounds(const sf::Shape& shape)
//{
//	this->bounds = shape.getGlobalBounds();
//}





float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}

Weapon* Character::getWeapon() const
{
	return this->wep;
}

void Character::takeDamage(int damage)
{
	this->health -= damage;
	cout << this->health << endl;
}

int Character::getHealth() const
{
	return this->health;
}

void Character::setHealth(int newHealth)
{
	this->health = newHealth;
}

void Character::setMoveSpeed(float newMoveSpeed)
{
	this->moveSpeed = newMoveSpeed;
}
