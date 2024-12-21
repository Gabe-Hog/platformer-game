#ifndef PROJECTILE_H
#define PROJECTILE_H
#include "Movable.h"

#include "Weapon.h"
using namespace std;

class Projectile : public Weapon
{
private:

	float speed;
	bool isMoving = false;
	sf::CircleShape shape = sf::CircleShape(5);
	sf::Vector2f targetPosition;
	vector<Projectile*> projectiles;


public:
	Projectile() = default;
	Projectile(float speed, int damage = 2);
	Projectile(float speed, sf::Vector2f ownerPosition, sf::Vector2f targetPosition);
	~Projectile();
	void attack(sf::Vector2f targetPosition) override;
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects& object1) override;
	void callDraw(sf::RenderTarget& target, sf::RenderStates states);
	bool hit();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	bool outOfBounds() const;
	vector<Projectile*> getProjectiles() const;



};

#endif