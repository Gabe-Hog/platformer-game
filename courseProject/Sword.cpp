#include "Sword.h"

Sword::Sword() : Weapon(3)
{
}

Sword::~Sword()
{
}

void Sword::attack(sf::Vector2f targetDirection)
{
}

void Sword::updatePosition(float dTime)
{
}

bool Sword::checkCollision(GameObjects& object1)
{
	return false;
}

void Sword::callDraw(sf::RenderTarget& target, sf::RenderStates states)
{
	
}







void Sword::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
