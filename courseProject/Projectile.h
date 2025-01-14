#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "DirectionVectorProcessor.h"
#include "GameObjects.h"
#include "Weapon.h"
#include <memory>
using namespace std;

class Projectile : public Weapon, public DirectionVectorProcessor
{
private:

	bool isMoving = false;
	sf::CircleShape shape = sf::CircleShape(5);
	sf::Vector2f targetPosition;
	vector<shared_ptr<Projectile>> projectiles;
	bool outOfBounds() const;


public:
	Projectile() = default;
	Projectile(int damage, float speed);
	Projectile(float speed, sf::Vector2f ownerPosition, sf::Vector2f targetPosition);
	~Projectile() = default;
	

	void updatePosition(float dTime) override;
	void checkCollision(GameObjects& object) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	void attack(sf::Vector2f targetPosition) override;
	
	vector<shared_ptr<Projectile>> getProjectiles() const;



};

#endif