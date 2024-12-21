#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"

using namespace std;
class Monster : public Character
{
private:
	
	
	float attackSpeed = 4.0f;
	sf::Vector2f randomPosition;
	Player* target;
	sf::RectangleShape monster;
	sf::CircleShape point = sf::CircleShape(10);

public:
	Monster() = default;
	Monster(Player* player);
	~Monster();
	void setDífficulty();

	void processDeath() override;

	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects& object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	




};

#endif