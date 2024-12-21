#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "SFML/Graphics.hpp"

class GameObjects : public sf::Drawable
{
private:
	sf::FloatRect bounds;

public:
	virtual ~GameObjects();
	virtual bool checkCollision(GameObjects& object1) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	void setBounds(sf::Shape& shape);
	virtual sf::FloatRect getBounds() const;




};
#endif
