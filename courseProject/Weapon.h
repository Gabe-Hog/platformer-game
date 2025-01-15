#ifndef WEAPON_H
#define WEAPON_H


#include "GameObjects.h"


class Character;


class Weapon : sf::Drawable
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
	void setDidHit(bool hit);

public:

	Weapon() = default;
	Weapon(float speed);
	Weapon(int damage, float speed = 6.f);
	virtual ~Weapon() = default;
	
	
	
	bool hit() const;

	void setOwnerPosition(sf::Vector2f newOwnerPosition);
	sf::Vector2f getOwnerPosition() const;

	virtual void checkCollision(GameObjects& object) = 0;
	virtual void updatePosition(float dTime) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	
	virtual void attack(sf::Vector2f targetDirection = { 0.f,0.f }) = 0;

};
#endif