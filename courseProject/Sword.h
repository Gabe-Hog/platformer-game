#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"
class Sword : public Weapon
{
private:
	float range = 5.0f;

public:
	Sword();
	~Sword();
	void attack() override;




};
#endif
