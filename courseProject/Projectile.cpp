#include "Projectile.h"

Projectile::Projectile(float speed) : speed(speed)
{
}

void Projectile::attack()
{
}

bool Projectile::checkCollision()
{
    return false;
}

bool Projectile::hit()
{
    return false;
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

