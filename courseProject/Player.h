#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Sword.h"

class Game;
class Player : public Character
{
private:

	 int unsigned score = 0;
	 sf::Vector2f velocity;
	 float jumpHeight = 150.f;
	 bool isJumping = false;

	 inline void movePlayer(float dTime);
	 inline void decreaseVelocityY(float dTime);

	
	 


public:

	Player() = default;
	Player(Game* gameInstance, void(Game::*onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Player(const Player& other);
	~Player();
	
	int getScore() const;
	string getStats() const;
	sf::Vector2f getVelocity() const;

	void setJumping(bool state);
	void setVelocity(sf::Vector2f newVel);

	void updateScore();
	void checkForDeath() override;
	void updatePosition(float dTime) override;
	void checkCollision(GameObjects & object1) override;
	
	virtual GameObjects* clone() override;
	


};

#endif