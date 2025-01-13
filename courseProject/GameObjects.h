#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "SFML/Graphics.hpp"

class GameObjects : public sf::Drawable
{
private:
	

public:

	GameObjects() = default;
	GameObjects(const GameObjects&) = default;
	virtual ~GameObjects() = default;
	virtual void checkCollision(GameObjects& object1) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

	


};
#endif
