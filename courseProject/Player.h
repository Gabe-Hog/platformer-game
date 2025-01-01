#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Sword.h"

class Game;
class Player : public Character
{
private:
	 int unsigned score = 0;
	 sf::RectangleShape player;
	 sf::Vector2f position; 
	 sf::Vector2f velocity;
	 float jumpHeight = 150.f;
	 bool isJumping = false;
	 void (Game::*deathCallBack)(const Player&) = nullptr;


public:

	Player();
	Player(void(Game::*deathCallBack)(const Player&), Game* gameInstance);
	~Player();
	
	int getScore() const;
	string getStats() const;
	sf::Shape* getPlayer();
	sf::Vector2f getVelocity() const;
	void updateScore();
	sf::Vector2f getPlayerPosition() const;
	void checkForDeath() override;
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects & object1) override;
	void setJumping(bool state);
	void setVelocity(sf::Vector2f newVel);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	
	/*void operator = (Player& other);*/


};

#endif