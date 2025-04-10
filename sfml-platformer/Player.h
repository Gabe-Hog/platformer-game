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
	
	 const float jumpHeight = 150.f; 
	 bool isJumping = false;

	 void movePlayer(float dTime);
	 void decreaseVelocityY(float dTime);

	
	 


public:

	Player() = default;
	Player(Game* gameInstance, void(Game::*onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);

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
	

};

#endif