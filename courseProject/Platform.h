#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameObjects.h"

class Platform : public GameObjects
{
private:
	sf::RectangleShape platform;
	sf::Color colour;



public:
	Platform() = default;
	Platform(sf::Vector2f pos, float width, float height, sf::Color colour = sf::Color(141, 128, 128));
	~Platform()=default;

	sf::FloatRect getBounds() const;
	void checkCollision(GameObjects & object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;




};
#endif