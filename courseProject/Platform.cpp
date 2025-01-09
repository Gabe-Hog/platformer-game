#include "Platform.h"
#include "Player.h"
#include <iostream>
Platform::Platform(sf::Vector2f pos, sf::Color colour, float width, float height) 
	: platform(sf::Vector2f(width, height))
{
	this->platform.setFillColor(colour);
	this->platform.setPosition(pos);

}

 

Platform::Platform(sf::Vector2f pos, float width, float height) : 
	platform(sf::Vector2f(width, height)), colour(141, 128, 128)
{
	this->platform.setFillColor(colour);
	this->platform.setPosition(pos);
	
}


Platform::~Platform()
{
}

sf::FloatRect Platform::getBounds() const
{
	return this->platform.getGlobalBounds();
}

void Platform::checkCollision(GameObjects & object)
{
	
	if(Player* player = dynamic_cast<Player*>(&object))
	{ 
		sf::FloatRect playerBounds = player->getSpriteBounds(); 
		sf::FloatRect platformBounds = this->getBounds();
		
		if (platformBounds.intersects(playerBounds))
		{
			if (playerBounds.top + playerBounds.height > platformBounds.top - playerBounds.height && player->getVelocity().y > 0)
			{
				player->setVelocity({ 0,0 });
				player->setSpritePosition({ player->getSpritePosition().x, platformBounds.top - playerBounds.height/2.f});
				player->setJumping(false);
				

			}
		}
		
		if (!platformBounds.intersects(playerBounds) && player->getVelocity().y > 0)
		{
			player->setJumping(true);
		}


	}


	
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->platform);
}

GameObjects* Platform::clone()
{
	return new Platform(*this);
}


