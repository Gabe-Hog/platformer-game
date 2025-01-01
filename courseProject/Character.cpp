#include "Character.h"
#include "Weapon.h"
#include <iostream>




Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed) :
	wep(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance()
{
}

Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance) :
	wep(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance(gameInstance)
{
}

Character::~Character()
{
	delete this->wep;
	

}







float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}

Game* Character::getGameInstancePointer() const
{
	return this->gameInstance;
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

string Character::getName() const
{
	return this->name;
}

void Character::setHealth(int newHealth)
{
	this->health = newHealth;
}

void Character::setMoveSpeed(float newMoveSpeed)
{
	this->moveSpeed = newMoveSpeed;
}
