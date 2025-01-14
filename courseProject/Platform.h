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
	Platform(sf::Vector2f pos, float width, float height);
	Platform(sf::Vector2f pos, sf::Color colour, float width, float height);
	~Platform()=default;

	sf::FloatRect getBounds() const;
	void checkCollision(GameObjects & object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;




};
#endif
