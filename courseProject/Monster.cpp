#include "Monster.h"

Monster::Monster(): Character(new Projectile(2))
{
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

void Monster::move()
{
}
