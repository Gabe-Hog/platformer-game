#include "Character.h"
#include "Weapon.h"
Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed) : wep(weapon), health(newHealth), moveSpeed(newMoveSpeed)
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
}

void Character::calcHealth()
{
}
