#include "Platform.h"
#include "Player.h"
#include <iostream>
Platform::Platform(sf::Vector2f pos, sf::Color colour, float width, float height) 
	: pos(pos), width(width), height(height), rect(sf::Vector2f(width, height))
{
	this->rect.setFillColor(colour);
	this->rect.setPosition(pos);
	this->setBounds(rect);
}

Platform::~Platform()
{
}

bool Platform::checkCollision(GameObjects & object)
{
	bool didCollide = false;
	if(Player* player = dynamic_cast<Player*>(&object))
	{ 
		sf::FloatRect playerBounds = player->getBounds(); 
		sf::FloatRect platformBounds = this->getBounds();
		
		if (platformBounds.intersects(playerBounds))
		{
			if (playerBounds.top + playerBounds.height > platformBounds.top - playerBounds.height && player->getVelocity().y > 0)
			{
				player->setVelocity({ 0,0 });
				player->getPlayer()->setPosition(player->getPlayer()->getPosition().x, platformBounds.top - playerBounds.height/2);
				player->setJumping(false);

				didCollide = true;

			}
		}
	}


	return didCollide;
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->rect);
}


