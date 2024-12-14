#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "SFML/Graphics.hpp"
class GameObjects : public sf::Drawable
{
private:


public:

	virtual bool checkCollision() = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


};
#endif
