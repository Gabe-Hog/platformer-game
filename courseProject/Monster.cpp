#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"
Monster::Monster(): Character(new Projectile(2), 50, "Ross", 200.f), monster(sf::Vector2f(100, 100))
{
    
    monster.setFillColor(sf::Color::Magenta);
    monster.setPosition(800,500);
    this->setBounds(monster);

}

Monster::~Monster()
{
}

bool Monster::checkCollision(GameObjects& object1)
{
    sf::FloatRect monsterBounds = this->getBounds();

	if (monster.getPosition().x  < 0.f)
	{
		monster.setPosition(0.f, monster.getPosition().y);
	}

	if (monster.getPosition().x + monsterBounds.width > WIDTH)
	{
		monster.setPosition(WIDTH - monsterBounds.width, monster.getPosition().y);
	}

	if (monster.getPosition().y + monsterBounds.height > HEIGHT)
	{
		
		monster.setPosition(monster.getPosition().x, HEIGHT - monsterBounds.height);
	}

	if (monster.getPosition().y < 0.f)
	{
		
		monster.setPosition(monster.getPosition().x, 0.f);
		
	}

    return false;
}

void Monster::setDífficulty()
{
}

Monster* Monster::respawn()
{
    return nullptr;
}

void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->monster);
}

void Monster::updatePosition(float dTime)
{
    this->setBounds(monster);
    sf::FloatRect monsterArea = this->getBounds();
    static sf::Vector2f direction;
    static float timeAccumulator = 0.0f;
    float interval = 2.f;
    timeAccumulator += dTime;
    
    if (monster.getPosition().x - this->randomPosition.x < pointProximity 
        && monster.getPosition().y - this->randomPosition.y < pointProximity)
    {
        
        int directionX = WIDTH/2.f + (rand()% (int)(WIDTH - WIDTH/2));
        int directionY = -(rand() % 601);
        
        this->randomPosition.x = directionX;
        this->randomPosition.y = directionY;
        
        direction = randomPosition - monster.getPosition();

    }
  
    this->monster.move(0.001f * direction * this->getMoveSpeed() * dTime);
       

       
  

}

