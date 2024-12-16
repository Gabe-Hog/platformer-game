#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameObjects.h"
#include "Weapon.h"


using namespace std;

class Character:public GameObjects
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
	virtual void updatePosition() = 0;
	void calcHealth();


};
#endif
