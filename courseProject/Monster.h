#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"
#include "Movable.h"

using namespace std;
class Game;
class Monster : public Character, public Movable
{
private:
	
	
	float attackSpeed = 4.0f;
	sf::Vector2f randomPosition;
	
	const Player& target;
	sf::CircleShape point = sf::CircleShape(10);
	void (*deathCallBack)(const Player&) = nullptr;



	void checkForDeath() override;
	void updatePosition(float dTime) override;
	void updateDifficulty();
	inline void makeAttackCheck(float &timeInterval, sf::Vector2f targetPosition);
	inline void moveMonster(float dTime, float &timeInterval);
	

protected:


public:
	Monster() = default;
	Monster(const Player& player, void (*deathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Monster(const Monster& other);
	~Monster();

	
	void checkCollision(GameObjects& object1) override;
	virtual GameObjects* clone() override;
	void setAttackSpeed(float newAttackSpeed);
	




};

#endif