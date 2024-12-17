#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameObjects.h"

class Platform : public GameObjects
{
private:
	sf::RectangleShape rect;
	sf::Vector2f pos;
	float width;
	float height;
	

public:
	Platform() = default;
	Platform(sf::Vector2f pos,sf::Color colourm, float width, float height);
	~Platform();
	bool checkCollision(GameObjects & object1) override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;




};
#endif
