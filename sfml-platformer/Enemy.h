#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"
#include "Player.h"
#include "Weapon.h"
#include "Projectile.h"
#include "DirectionVectorProcessor.h"

using namespace std;

class Enemy : public Character, public DirectionVectorProcessor
{
private:
	
	
	float attackSpeed = 2.0f;
	sf::Vector2f randomPosition;
	const Player& target;

	
	void updateDifficulty();
	inline void makeAttackCheck(float &timeInterval, sf::Vector2f targetPosition);
	inline void moveEnemy(float dTime, float &timeInterval);
	


public:

	Enemy() = default;
	Enemy(const Player& player, Game* gameInstance, void(Game::* onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	~Enemy();

	void setAttackSpeed(float newAttackSpeed);
	
	void checkForDeath() override;
	void updatePosition(float dTime) override;
	void checkCollision(GameObjects& object1) override;


};

#endif