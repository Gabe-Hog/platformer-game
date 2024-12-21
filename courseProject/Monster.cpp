#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Game.h"
#include <math.h>
//Monster::Monster(): Character(new Projectile(2), 40, "Ross", 200.f), monster(sf::Vector2f(100, 100))
//{
//    
//    this->monster.setFillColor(sf::Color::Magenta);
//    this->monster.setOrigin(50,50);
//    this->monster.setPosition(800,500);
//    this->point.setPosition(800, 500);
//    point.setOrigin(this->point.getRadius(), this->point.getRadius());
//    this->setBounds(monster);
//
//}

Monster::Monster(Player* player) : Character(new Projectile(200), 40, "Ross", 200.f), monster(sf::Vector2f(100, 100)), target(player)
{
    this->monster.setFillColor(sf::Color::Magenta);
    this->monster.setOrigin(50, 50);
    this->monster.setPosition(800, 500);
    this->point.setPosition(800, 500);
    point.setOrigin(this->point.getRadius(), this->point.getRadius());
    this->setBounds(monster);
    this->randomPosition = this->monster.getPosition();

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

	if (monster.getPosition().x + monsterBounds.width/2 > WIDTH)
	{
		monster.setPosition(WIDTH - monsterBounds.width/2, monster.getPosition().y);
	}

	if (monster.getPosition().y + monsterBounds.height/2 > HEIGHT)
	{
		
		monster.setPosition(monster.getPosition().x, HEIGHT - monsterBounds.height);
	}

	if (monster.getPosition().y < 0.f)
    {
		monster.setPosition(monster.getPosition().x, 0.f);
	}

    this->getWeapon()->checkCollision(object1);


    return false;
}

void Monster::setDífficulty()
{
}

void Monster::processDeath()
{

}



void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->monster);
    this->getWeapon()->callDraw(target, states);
    
}

void Monster::updatePosition(float dTime)
{
    this->setBounds(monster);
    this->getWeapon()->setOwnerPosition(monster.getPosition());
    sf::FloatRect monsterArea = this->getBounds();
    sf::Vector2f targetPosition = this->target->getPlayerPosition();
    static float timeAccumulator = 0.0f;
    timeAccumulator += dTime;

    if (timeAccumulator > this->attackSpeed)
    {
        this->getWeapon()->attack(targetPosition);
        timeAccumulator = 0;
    }
    if (monsterArea.contains(randomPosition))
    {
        int directionX = (int)(WIDTH/2.f) + (rand()% (int)(WIDTH - WIDTH/2));
        int directionY = (rand() % (int)HEIGHT);
        
        this->randomPosition.x = directionX;
        this->randomPosition.y = directionY;

        point.setPosition(randomPosition);
    }
    
    this->setDirection(randomPosition - (monster.getPosition()));
  
    
    this->getWeapon()->updatePosition(dTime);
    this->monster.move(getNormalizedDirection() * this->getMoveSpeed() * dTime);
       

       
  

}

