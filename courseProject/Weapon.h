#ifndef WEAPON_H
#define WEAPON_H


#include "Movable.h"


class Character;


class Weapon : public Movable
{
private:

	int damage = 1;
	bool didHit = false;
	sf::Vector2f ownerPosition;

public:

	Weapon() = default;
	Weapon(int damage);
	virtual ~Weapon() = default;
	virtual void callDraw(sf::RenderTarget& target, sf::RenderStates states) = 0;
	virtual void attack(sf::Vector2f targetDirection = {0.f,0.f}) = 0;
	virtual void updatePosition(float dTime) = 0;
	void setDidHit(bool hit);
	bool hit() const;
	void setOwnerPosition(sf::Vector2f newOwnerPosition);
	sf::Vector2f getOwnerPosition() const;
	void dealDamage(Character& character) const;

};
#endif