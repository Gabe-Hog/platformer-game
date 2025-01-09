#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"

#include "SFML/Graphics.hpp"

class Sword : public Weapon
{
private:

	
	bool isSwinging = false;

	sf::Sprite swordSprite;
	sf::Texture swordTexture;

public:

	Sword() = default;
	Sword(sf::Texture texture);
	~Sword() = default;
	void attack(sf::Vector2f targetDirection) override;
	void updatePosition(float dTime) override;
	void checkCollision(GameObjects& object1) override;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	virtual Weapon* clone() override;



};
#endif
