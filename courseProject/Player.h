#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "Sword.h"

class Player : public Character
{
private:
	 int unsigned score = 0;
	 sf::RectangleShape player;
	 sf::Vector2f position; 


public:

	Player();
	~Player();

	int getScore() const;
	void updateScore();
	void updatePosition() override;
	bool checkCollision() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};
#endif