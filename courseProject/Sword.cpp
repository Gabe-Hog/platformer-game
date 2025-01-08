#include "Sword.h"
#include "Monster.h"

Sword::Sword(sf::Texture texture) 
	: Weapon(3), swordTexture(texture)
{
	
	sf::FloatRect bounds = swordSprite.getLocalBounds();
	this->swordSprite.setScale(0.05f, -0.065f);
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
	this->setBounds(swordSprite);
	
	if(this->isSwinging)
	{
		this->swordSprite.setPosition(this->getOwnerPosition().x, this->getOwnerPosition().y);
		this->swordSprite.setRotation(rotation += this->swingSpeed);
		this->swordSprite.setPosition(this->getOwnerPosition().x + 20, this->getOwnerPosition().y - 30);
		if(rotation > 140)
		{
			this->isSwinging = false;
			this->setDidHit(false);
			rotation = 0.f;
			this->swordSprite.setRotation(rotation);
			
		}
	}
}

void Sword::checkCollision(GameObjects& object1)
{
	if (Monster* monster = dynamic_cast<Monster*>(&object1))
	{
		sf::FloatRect monsterBounds = monster->getBounds();
		sf::FloatRect swordBounds = this->getBounds();
		if (swordBounds.intersects(monsterBounds) && this->hit() == false)
		{
			this->dealDamage(*monster);
			this->setDidHit(true);
			
	
		}


	}
	
}

void Sword::callDraw(sf::RenderTarget& target, sf::RenderStates states)
{

	/*sf::FloatRect bounds = swordSprite.getGlobalBounds(); 
	sf::RectangleShape boundingBox(sf::Vector2f(bounds.width, bounds.height)); 
	boundingBox.setPosition(bounds.left, bounds.top); 
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1.f); 
	sf::CircleShape originMarker(2.f); 
	originMarker.setFillColor(sf::Color::Green); 
	originMarker.setPosition(swordSprite.getPosition().x - 2, swordSprite.getPosition().y - 2); 
	target.draw(originMarker);
	target.draw(boundingBox);*/


	if (this->isSwinging)
	{
		target.draw(this->swordSprite);
	}
}







void Sword::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

Weapon* Sword::clone()
{
	return new Sword(*this);
}
