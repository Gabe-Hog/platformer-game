#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "GameObjects.h"
#include "Weapon.h"
class Projectile : public Weapon, public GameObjects
{
private:

	float speed;



public:
	Projectile(float speed);

	void attack() override;
	bool checkCollision(GameObjects& object1) override;
	bool hit();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;




};

#endif