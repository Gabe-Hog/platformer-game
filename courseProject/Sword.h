#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"
#include "SFML/Graphics.hpp"
class Sword : public Weapon
{
private:
	float swingSpeed= 6.0f;
	bool isSwinging = false;
	sf::RectangleShape sword;


public:
	Sword();
	~Sword();
	void attack(sf::Vector2f targetDirection) override;
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects& object1) override;
	void callDraw(sf::RenderTarget& target, sf::RenderStates states);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};
#endif
