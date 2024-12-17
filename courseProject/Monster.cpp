#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"
Monster::Monster(): Character(new Projectile(2), 50, "Ross", 4.f), position(800, 500), monster(sf::Vector2f(100, 100))
{
    
    monster.setFillColor(sf::Color::Magenta);
    monster.setPosition(position);
    this->setBounds(monster);

}

Monster::~Monster()
{
}

bool Monster::checkCollision(GameObjects& object1)
{
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
    sf::Vector2f direction(0.f, 0.f);
    static float timeAccumulator = 0.0f;
    float interval = 2.f;
    timeAccumulator += dTime;

    if (timeAccumulator >= interval)
    {
        int randomDirection = rand() % 4;

        if (randomDirection == 0 && monsterArea.left + monsterArea.width <= WIDTH) 
        { this->monster.move(this->getMoveSpeed(), 0); } 
        else if (randomDirection == 1 && monsterArea.left >= WIDTH / 2) 
        { this->monster.move(-this->getMoveSpeed(), 0); } 
        else if (randomDirection == 2 && monsterArea.top >= 0.0f) 
        { this->monster.move(0.f, -this->getMoveSpeed()); } 
        else if (randomDirection == 3 && monsterArea.top + monsterArea.height <= HEIGHT) {
            this->monster.move(0.f, this->getMoveSpeed());
        }
    }

}

