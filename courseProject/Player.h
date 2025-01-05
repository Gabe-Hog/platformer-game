#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Sword.h"

class Game;
class Player : public Character
{
private:

	 int unsigned score = 0;
	 sf::Sprite playerSprite;
	 sf::Vector2f position; 
	 sf::Vector2f velocity;
	
	 float jumpHeight = 150.f;
	 bool isJumping = false;
	 void (Game::*deathCallBack)(const Player&) = nullptr;
	 


public:

	Player() = default;
	Player(void(Game::*deathCallBack)(const Player&), Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Player(const Player& other);
	~Player();
	
	int getScore() const;
	string getStats() const;
	sf::Sprite* getPlayer();
	sf::Vector2f getVelocity() const;
	void updateScore();
	sf::Vector2f getPlayerPosition() const;
	void checkForDeath() override;
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects & object1) override;
	void setJumping(bool state);
	void setVelocity(sf::Vector2f newVel);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual GameObjects* clone() override;
	


};

#endif