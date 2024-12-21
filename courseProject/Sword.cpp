#include "Sword.h"
#include "Monster.h"

Sword::Sword() 
	: Weapon(3), sword(sf::Vector2f(100, 5))
{
	this->sword.setFillColor(sf::Color::White);
	this->sword.setRotation(-90);
}

Sword::~Sword()
{
}

void Sword::attack(sf::Vector2f targetDirection)
{
	
	this->isSwinging = true;
	
}

void Sword::updatePosition(float dTime)
{
	static int rotation = -90;
	this->setBounds(sword);
	if(this->isSwinging)
	{
		this->sword.setPosition(this->getOwnerPosition().x + 35, this->getOwnerPosition().y);
		this->sword.setRotation(rotation += this->swingSpeed);

		if(rotation > 30)
		{
			this->isSwinging = false;
			this->setDidHit(false);
			rotation = -90;
			
		}
	}
}

bool Sword::checkCollision(GameObjects& object1)
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
	return false;
}

void Sword::callDraw(sf::RenderTarget& target, sf::RenderStates states)
{
	if (this->isSwinging)
	{
		target.draw(this->sword);
	}
}







void Sword::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
