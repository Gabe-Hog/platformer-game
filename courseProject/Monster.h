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
	sf::Sprite monsterSprite;
	void (*deathCallBack)(const Player&) = nullptr;

public:
	Monster() = default;
	Monster(const Player& player, void (*deathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Monster(const Monster& other);
	~Monster();
	

	void checkForDeath() override;

	void updatePosition(float dTime) override;
	void updateDifficulty();
	bool checkCollision(GameObjects& object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual GameObjects* clone() override;
	void setAttackSpeed(float newAttackSpeed);
	




};

#endif