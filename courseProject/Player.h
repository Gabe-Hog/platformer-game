#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Sword.h"

class Player : public Character
{
private:
	 int unsigned score = 0;
	 Sword* sword;


public:
	Player();
	void move() override;
	int getScore() const;
	void updateScore();




};
#endif