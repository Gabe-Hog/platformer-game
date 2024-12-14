#ifndef PLATFORM_H
#define PLATFORM_H
#include "GameObjects.h"
class Platform : public GameObjects
{
private:
	sf::RectangleShape rect;

	float width;
	float height;
	

public:
	Platform() = default;
	Platform(float windowWidth, float windowHeight,sf::Color colourm, float width, float height);
	~Platform();
	bool checkCollision() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;




};
#endif
