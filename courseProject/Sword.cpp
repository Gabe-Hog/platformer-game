#include "Sword.h"
#include "Enemy.h"

Sword::Sword(sf::Texture texture) 
	: Weapon(3), swordTexture(texture)
{
	
	sf::FloatRect bounds = swordSprite.getLocalBounds();
	this->swordSprite.setScale(0.05f, -0.052f);
	this->swordSprite.setOrigin(bounds.width / 2.f, bounds.height/2.f);
	this->swordSprite.setTexture(this->swordTexture);

}

void Sword::attack(sf::Vector2f targetDirection)
{
	
	this->isSwinging = true;
	
}

void Sword::updatePosition(float dTime)
{
	static float rotation = 0.f;
	this->swordSprite.setPosition(this->getOwnerPosition().x + 20, this->getOwnerPosition().y - 30);
	if(this->isSwinging)
	{
		
		this->swordSprite.setRotation(rotation += this->getSpeed());
	
		if(rotation > 140)
		{
			this->isSwinging = false;
			rotation = 0.f;
			this->swordSprite.setRotation(rotation);
			this->setDidHit(false);
			
		}
	}
}

void Sword::checkCollision(GameObjects& object)
{
	if (Enemy* enemy = dynamic_cast<Enemy*>(&object))
	{
		sf::FloatRect enemyBounds = enemy->getSpriteBounds();
		sf::FloatRect swordBounds = this->swordSprite.getGlobalBounds();
		if (swordBounds.intersects(enemyBounds) && this->hit() == false && this->isSwinging)
		{
			this->dealDamage(*enemy);
			this->setDidHit(true);
			
	
		}


	}
	
}




void Sword::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	if (this->isSwinging)
	{
		target.draw(this->swordSprite);
	}
}


