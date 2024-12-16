#include "Platform.h"

Platform::Platform(float windowWidth, float windowHeight, sf::Color colour, float width, float height) 
	: width(width), height(height), rect(sf::Vector2f(width, height))
{
	this->rect.setFillColor(colour);
	this->rect.setPosition(windowWidth/1.9f, windowHeight/2.1f);
	
}

Platform::~Platform()
{
}

bool Platform::checkCollision()
{
	return false;
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rect);
}
