#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Movable.h"



using namespace std;


class Weapon;

class Character:public Movable
{
private:
	int health;
	string name;
	Weapon* wep;
	float moveSpeed;
	

public:
	Character() = default;
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed);
	~Character();
	

	float getMoveSpeed() const;
	virtual void processDeath() = 0;
	virtual void updatePosition(float dTime) = 0;
	Weapon* getWeapon() const;
	void takeDamage(int damage);
	void calcHealth();


};
#endif
