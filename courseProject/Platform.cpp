#include "Platform.h"
#include "Player.h"


Platform::Platform(sf::Vector2f pos, float width, float height, sf::Color colour) : 
	platform(sf::Vector2f(width, height)), colour(colour)
{
	this->platform.setFillColor(colour);
	this->platform.setPosition(pos);
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
		
		if (platformBounds.intersects(playerBounds) && playerBounds.top + playerBounds.height > platformBounds.top - playerBounds.height 
			&& player->getVelocity().y > 0)
		{
			
			player->setVelocity({ 0.f,0.f });
			player->setSpritePosition({ player->getSpritePosition().x, platformBounds.top - playerBounds.height/2.f});
			player->setJumping(false);
			
		}
		
		else if (!platformBounds.intersects(playerBounds) && player->getVelocity().y > 0)
		{
			player->setJumping(true);
		}
	}
}

void Platform::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->platform);
}
