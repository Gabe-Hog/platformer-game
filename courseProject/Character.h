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


public:
	Character(Weapon* weapon);
	~Character();


	virtual void move() = 0;
	void calcHealth();


};
#endif
