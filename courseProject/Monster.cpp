#include "Monster.h"
#include <cstdlib>
#include <ctime>
#include "Game.h"
Monster::Monster(): Character(new Projectile(2), 50, "Ross", 0.5f), position(800, 500), monster(sf::Vector2f(100, 100))
{
    monster.setFillColor(sf::Color::Magenta);
    monster.setPosition(position);
}

Monster::~Monster()
{
}

bool Monster::checkCollision()
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

void Monster::updatePosition()
{
    sf::FloatRect monsterArea = this->monster.getGlobalBounds();
    srand(time(0));
    float randomDirection = rand() % 4;
    if (randomDirection == 0 && monsterArea.left + monsterArea.width <= WIDTH)
    {
        this->monster.move(this->getMoveSpeed(), 0);
    }
    else if (randomDirection == 1 && monsterArea.left >= 0.0f)
    {
        this->monster.move(-this->getMoveSpeed(), 0);
    }
    else if (randomDirection == 2 && monsterArea.top >= 0.0f)
    {
        this->monster.move(0.f, -this->getMoveSpeed());
    }
    else if(randomDirection == 3 && monsterArea.top + monsterArea.height <= HEIGHT)
    {
        this->monster.move(0.f, this->getMoveSpeed());
    }
}
