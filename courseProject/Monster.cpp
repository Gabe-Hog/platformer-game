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
    this->setCharacterTexture("enemyOven");
    this->assignTexture();
    this->setSpritePosition({ 850, 550 });
    this->setSpriteBounds();
    this->setSpriteOrigin();
    this->point.setPosition(800, 500);
    
    point.setOrigin(this->point.getRadius(), this->point.getRadius());
    this->randomPosition = { 850, 550 };
    this->setNameTextPosition({ WIDTH-100.f, 0.f });

}

Monster::Monster(const Monster& other) : Character(other), attackSpeed(other.attackSpeed), randomPosition(other.randomPosition), target(other.target),
point(other.point), deathCallBack(other.deathCallBack)
{
}

Monster::~Monster()
{
}





void Monster::checkCollision(GameObjects& object1)
{
    sf::FloatRect monsterBounds = this->getBounds();
    sf::Vector2f monsterPosition = this->getSpritePosition();
    
	if (monsterPosition.x < 0.f)
	{
        this->setSpritePosition({ monsterPosition.x, monsterPosition.y });
	}

	if (monsterPosition.x + monsterBounds.width/2 > WIDTH)
	{
        this->setSpritePosition({ WIDTH - monsterBounds.width / 2, monsterPosition.y });
	}

	/*if (monsterPosition.y + monsterBounds.height > HEIGHT)
	{
		
        this->setSpritePosition({ monsterPosition.x, HEIGHT - monsterBounds.height/2.f});
	}*/

	if (monsterPosition.y < 0.f)
    {
        this->setSpritePosition({ monsterPosition.x, 0.f });
	}

    this->getWeapon()->checkCollision(object1);


 
}


void Monster::checkForDeath()
{
    
    if (this->getHealth() <= 0)
    {
        this->deathCallBack(this->target);
        
        this->updateDifficulty();
        this->setSpritePosition({ 800, 500 });
       
    }


    
}




GameObjects* Monster::clone()
{
    return new Monster(*this);
}

void Monster::setAttackSpeed(float newAttackSpeed)
{
    this->attackSpeed = newAttackSpeed;
}

inline void Monster::makeAttackCheck(float &timeInterval, sf:: Vector2f targetPosition)
{
    if (timeInterval > this->attackSpeed)
    {
        this->getWeapon()->attack(targetPosition);
        timeInterval = 0;
    }
}

inline void Monster::moveMonster(float dTime, float &timeInterval)
{
    sf::FloatRect monsterArea = this->getBounds();
    if (monsterArea.contains(this->randomPosition))
    {
       
        int directionX = (int)(WIDTH / 2.f) + (rand() % (int)(WIDTH - WIDTH / 2));
        int directionY = (rand() % (int)HEIGHT);

        this->randomPosition.x = directionX;
        this->randomPosition.y = directionY;

        this->point.setPosition(this->randomPosition);

    }


    this->setDirection(this->randomPosition - this->getSpritePosition());

    this->getWeapon()->updatePosition(dTime);
    this->moveCharacterSprite(getNormalizedDirection() * this->getMoveSpeed() * dTime);




}



void Monster::updatePosition(float dTime)
{
    
    this->setSpriteBounds();
    this->getWeapon()->setOwnerPosition(this->getSpritePosition());
    
    sf::Vector2f targetPosition = this->target.getSpritePosition();
    static float timeAccumulator = 0.0f;
    timeAccumulator += dTime;

    this->makeAttackCheck(timeAccumulator, targetPosition);
    this->moveMonster(dTime, timeAccumulator);
   
    this->checkForDeath();
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

