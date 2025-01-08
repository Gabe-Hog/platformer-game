#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Movable.h"
#include "GameObjects.h"
#include "Weapon.h"
#include <memory>
using namespace std;

class Projectile : public Weapon, public Movable
{
private:

	float speed;
	bool isMoving = false;
	sf::CircleShape shape = sf::CircleShape(5);
	sf::Vector2f targetPosition;
	vector<shared_ptr<Projectile>> projectiles;


public:
	Projectile() = default;
	Projectile(float speed, int damage = 1);
	Projectile(float speed, sf::Vector2f ownerPosition, sf::Vector2f targetPosition);
	Projectile(const Projectile& other);
	~Projectile() = default;
	void attack(sf::Vector2f targetPosition) override;
	void updatePosition(float dTime) override;
	void checkCollision(GameObjects& object1) override;
	void callDraw(sf::RenderTarget& target, sf::RenderStates states);
	void removeProjectile();
	
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual Weapon* clone() override;
	bool outOfBounds() const;
	vector<shared_ptr<Projectile>> getProjectiles() const;



};

#endif