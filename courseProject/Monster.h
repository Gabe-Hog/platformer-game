#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Projectile.h"

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

	void updatePosition() override;
	bool checkCollision() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	




};

#endif