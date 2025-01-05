#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <utility>
#include "Game.h"

Monster::Monster(const Player& player , void (*deathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler):
    Character(new Projectile(200), 20, "Ross", 200.f, fontHandler, textureHandler), target(player) , deathCallBack(deathCallBack)
{


    this->setSpriteTexture("enemyOven");
    monsterSprite = getReferenceToSprite();
    this->monsterSprite.setPosition(850, 550);
    sf::FloatRect bounds = this->monsterSprite.getLocalBounds();
    monsterSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);


    this->monsterSprite.setOrigin(50, 50);
    this->monsterSprite.setPosition(850, 550);
    this->point.setPosition(800, 500);
    point.setOrigin(this->point.getRadius(), this->point.getRadius());
    this->setBounds(monsterSprite);
    this->randomPosition = this->monsterSprite.getPosition();

}

Monster::Monster(const Monster& other) : Character(other), attackSpeed(other.attackSpeed), randomPosition(other.randomPosition), target(other.target),
monsterSprite(other.monsterSprite), point(other.point), deathCallBack(other.deathCallBack)
{
}

Monster::~Monster()
{
}



bool Monster::checkCollision(GameObjects& object1)
{
    sf::FloatRect monsterBounds = this->getBounds();

	if (monsterSprite.getPosition().x  < 0.f)
	{
		monsterSprite.setPosition(0.f, monsterSprite.getPosition().y);
	}

	if (monsterSprite.getPosition().x + monsterBounds.width/2 > WIDTH)
	{
		monsterSprite.setPosition(WIDTH - monsterBounds.width/2, monsterSprite.getPosition().y);
	}

	if (monsterSprite.getPosition().y + monsterBounds.height/2 > HEIGHT)
	{
		
		monsterSprite.setPosition(monsterSprite.getPosition().x, HEIGHT - monsterBounds.height);
	}

	if (monsterSprite.getPosition().y < 0.f)
    {
		monsterSprite.setPosition(monsterSprite.getPosition().x, 0.f);
	}

    this->getWeapon()->checkCollision(object1);


    return false;
}


void Monster::checkForDeath()
{
    
    if (this->getHealth() <= 0)
    {
        this->deathCallBack(this->target);
        
        this->updateDifficulty();
        this->monsterSprite.setPosition(800, 500);
       
    }


    
}



void Monster::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->monsterSprite);
    this->getWeapon()->callDraw(target, states);
    
}

GameObjects* Monster::clone()
{
    return new Monster(*this);
}

void Monster::setAttackSpeed(float newAttackSpeed)
{
    this->attackSpeed = newAttackSpeed;
}

void Monster::updatePosition(float dTime)
{
    this->checkForDeath();
    this->setBounds(monsterSprite);
    this->getWeapon()->setOwnerPosition(monsterSprite.getPosition());
    sf::FloatRect monsterArea = this->getBounds();
    sf::Vector2f targetPosition = this->target.getPlayerPosition();
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
    

    this->setDirection(randomPosition - (monsterSprite.getPosition()));
  
    
    this->getWeapon()->updatePosition(dTime);
    this->monsterSprite.move(getNormalizedDirection() * this->getMoveSpeed() * dTime);
       

       
  

}

void Monster::updateDifficulty()
{
    static int health = 20;

    health += 5;
    float moveSpeed = this->getMoveSpeed();
    this->setHealth(health);
    this->setMoveSpeed(moveSpeed+30);
    if (this->attackSpeed <= 1)
    {
        this->setAttackSpeed(this->attackSpeed - 0.02f);
    }
    else
    {
        this->setAttackSpeed(this->attackSpeed - 1);
    }
    
   
}

