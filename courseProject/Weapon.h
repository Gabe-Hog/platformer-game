#ifndef WEAPON_H
#define WEAPON_H


#include "GameObjects.h"


class Character;


class Weapon : public GameObjects
{
private:

	int damage = 1;
	float speed;
	bool didHit = false;
	sf::Vector2f ownerPosition;
	 
protected:
	float getSpeed() const;
	int getDamage() const;
	void dealDamage(Character& character) const;
public:

	Weapon() = default;
	Weapon(float speed);
	Weapon(int damage, float speed = 6.f);
	virtual ~Weapon() = default;
	virtual void attack(sf::Vector2f targetDirection = {0.f,0.f}) = 0;
	void setDidHit(bool hit);
	bool hit() const;
	void setOwnerPosition(sf::Vector2f newOwnerPosition);
	sf::Vector2f getOwnerPosition() const;
	virtual void checkCollision(GameObjects& object) = 0;
	virtual void updatePosition(float dTime) = 0;
	
	

};
#endif