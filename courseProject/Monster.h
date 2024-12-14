#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Projectile.h"
class Monster : Character
{
private:

	float moveSpeed = 3.0f;
	float attackSpeed = 2.0f;

public:

	Monster();
	~Monster();

	bool checkCollision() override;
	void setDífficulty();
	Monster* respawn(); 
	void move() override;




};

#endif