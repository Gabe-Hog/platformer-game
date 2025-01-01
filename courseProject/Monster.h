#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"


using namespace std;
class Game;
class Monster : public Character
{
private:
	
	
	float attackSpeed = 4.0f;
	sf::Vector2f randomPosition;
	const Player& target;
	sf::RectangleShape monster;
	sf::CircleShape point = sf::CircleShape(10);
	void (*deathCallBack)(const Player&) = nullptr;

public:
	Monster() = default;
	Monster(const Player& player, void (*deathCallBack)(const Player&));
	~Monster();
	

	void checkForDeath() override;

	void updatePosition(float dTime) override;
	void updateDifficulty();
	bool checkCollision(GameObjects& object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	void setAttackSpeed(float newAttackSpeed);
	




};

#endif