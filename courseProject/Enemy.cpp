#include "Enemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include <utility>
#include "Game.h"



Enemy::Enemy(const Player& player, Game* gameInstance, void(Game::*onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
    Character(new Projectile(1, 200), 20, "Ross", 200.f, gameInstance, onDeathCallBack, fontHandler, textureHandler), target(player)
{
    this->setCharacterTexture("enemyOven");
    this->setTextureToSprite();
    this->setSpritePosition({ 850, 550 });
    this->setSpriteOrigin();
    
    this->randomPosition = { 850, 550 };
    this->setNameTextPosition({ WIDTH - 100.f, 0.f });
}



Enemy::~Enemy()
{
}





void Enemy::checkCollision(GameObjects& object)
{
    sf::FloatRect enemyBounds = this->getSpriteBounds();
    sf::Vector2f enemyPosition = this->getSpritePosition();
    
    if (Player* player = dynamic_cast<Player*>(&object))
    {
        if (enemyBounds.intersects(player->getSpriteBounds()))
        {
            player->setSpritePosition({ player->getSpritePosition().x - enemyBounds.width/2.f, player->getSpritePosition().y });
        }
    }

    this->getWeapon()->checkCollision(object);


 
}


void Enemy::checkForDeath()
{
    
    if (this->getHealth() <= 0)
    {
        this->invokeOnDeath(this->target);
        this->updateDifficulty();
        this->setSpritePosition({ 850, 550 });

       
    }

}





void Enemy::setAttackSpeed(float newAttackSpeed)
{
    this->attackSpeed = newAttackSpeed;
}

inline void Enemy::makeAttackCheck(float &timeInterval, sf:: Vector2f targetPosition)
{
    if (timeInterval > this->attackSpeed)
    {
        this->getWeapon()->attack(targetPosition);
        timeInterval = 0;
    }
}


inline void Enemy::moveEnemy(float dTime, float &timeInterval)
{
    sf::FloatRect monsterArea = this->getSpriteBounds();
    if (monsterArea.contains(this->randomPosition))
    {
       
        int directionX = (int)(WIDTH / 2.f) + (rand() % (int)(WIDTH - WIDTH / 2));
        int directionY = (rand() % (int)HEIGHT);

        this->randomPosition.x = directionX;
        this->randomPosition.y = directionY;

    }

    this->setDirection(this->randomPosition - this->getSpritePosition());

    this->getWeapon()->updatePosition(dTime);
    this->moveCharacterSprite(getNormalizedDirection() * this->getMoveSpeed() * dTime);

}



void Enemy::updatePosition(float dTime)
{
    
   
    this->getWeapon()->setOwnerPosition(this->getSpritePosition());
    
    sf::Vector2f targetPosition = this->target.getSpritePosition();
    static float timeAccumulator = 0.0f;
    timeAccumulator += dTime;

    this->makeAttackCheck(timeAccumulator, targetPosition);
    this->moveEnemy(dTime, timeAccumulator);
   
   
}

void Enemy::updateDifficulty()
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

