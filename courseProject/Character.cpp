#include "Character.h"

Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed) : wep(weapon), health(newHealth), moveSpeed(newMoveSpeed)
{
}

Character::~Character()
{
}

float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}

void Character::calcHealth() 
{
}
