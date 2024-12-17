#ifndef PLAYER_H
#define PLAYER_H
#include "GameObjects.h"
#include "Character.h"
#include "Sword.h"


class Player : public Character
{
private:
	 int unsigned score = 0;
	 sf::RectangleShape player;
	 sf::Vector2f position; 
	 sf::Vector2f velocity;
	 float jumpHeight = 200.f;
	 bool isJumping = false;


public:

	Player();
	~Player();

	int getScore() const;
	sf::Shape* getPlayer();
	sf::Vector2f getVelocity() const;
	void updateScore();
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects & object1) override;
	void setJumping(bool state);
	void setVelocity(sf::Vector2f newVel);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};
#endif