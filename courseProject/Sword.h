#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"

#include "SFML/Graphics.hpp"

class Sword : public Weapon
{
private:
	float swingSpeed= 6.0f;
	bool isSwinging = false;
	sf::Sprite swordSprite;
	sf::Texture swordTexture;
	sf::RectangleShape sword;


public:
	Sword() = default;
	Sword(sf::Texture texture);
	~Sword() = default;
	void attack(sf::Vector2f targetDirection) override;
	void updatePosition(float dTime) override;
	bool checkCollision(GameObjects& object1) override;
	void callDraw(sf::RenderTarget& target, sf::RenderStates states);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual Weapon* clone() override;



};
#endif
