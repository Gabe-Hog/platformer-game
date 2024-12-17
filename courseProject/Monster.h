#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Projectile.h"
#include "GameObjects.h"

class Monster : public Character
{
private:
	
	
	float attackSpeed = 2.0f;
	sf::RectangleShape monster;
	sf::Vector2f position;

public:

	Monster();
	~Monster();

	void setDífficulty();
	Monster* respawn(); 

	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects& object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	




};

#endif