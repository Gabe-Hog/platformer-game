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

	 void (Game::*deathCallBack)(const Player&) = nullptr;
	 


public:

	Player() = default;
	Player(void(Game::*deathCallBack)(const Player&), Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Player(const Player& other);
	~Player();
	
	int getScore() const;
	string getStats() const;
	
	sf::Vector2f getVelocity() const;
	void updateScore();
	void checkForDeath() override;
	void updatePosition(float dTime) override;
	void checkCollision(GameObjects & object1) override;
	void setJumping(bool state);
	void setVelocity(sf::Vector2f newVel);
	
	virtual GameObjects* clone() override;
	


};

#endif