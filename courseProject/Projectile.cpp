#include "Projectile.h"
#include "Character.h"
#include "Platform.h"
#include "Game.h"
#include <algorithm>

Projectile::Projectile(float speed, int damage) : Weapon(damage), speed(speed)
{
    
    
}

Projectile::Projectile(float speed, sf::Vector2f ownerPosition, sf::Vector2f targetPosition) : speed(speed),   targetPosition(targetPosition)
{
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->setBounds(shape);
    this->shape.setFillColor(sf::Color::White);
    this->shape.setPosition(ownerPosition);
}

Projectile::Projectile(const Projectile& other) : Weapon(other), speed(other.speed), isMoving(other.isMoving), shape(shape), targetPosition(other.targetPosition)
{
}








void Projectile::attack(sf::Vector2f targetDirection)
{
    sf::Vector2f test = this->getOwnerPosition();
    this->projectiles.push_back(make_shared<Projectile>(this->speed, this->getOwnerPosition(), targetDirection));
    
    for (auto& projectile : this->projectiles)
    {
        if (projectile->isMoving == false)
        {
            projectile->setDirection(projectile->targetPosition - projectile->shape.getPosition());
            
        }
    }




}


void Projectile::updatePosition(float dTime)
{
    for (auto& projectile : this->projectiles)
    {
        projectile->shape.move(projectile->getNormalizedDirection() * projectile->speed * dTime);
        projectile->isMoving = true;
     
       
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(),
        [](const shared_ptr<Projectile>& projec) {return projec->outOfBounds() || projec->hit();
        }),
    projectiles.end());

  
}

bool Projectile::checkCollision(GameObjects& object1)
{
    bool didCollide = false;
    for (auto& projectile : this->projectiles)
    
    {
        
        if (Character* character = dynamic_cast<Character*>(&object1))
        {

            if (character->getBounds().contains(projectile->shape.getPosition()))
            {
                didCollide = true;
                
                
                this->dealDamage(*character);
                projectile->setDidHit(true);
            }
        }
        else if (Platform* platform = dynamic_cast<Platform*>(&object1))
        {
            sf::FloatRect platformBounds = platform->getBounds();
            if (platformBounds.contains(projectile->shape.getPosition()))
            {
                
                projectile->setDidHit(true);
                didCollide = true;
            }

        }

        
    }

    return didCollide;
}

void Projectile::callDraw(sf::RenderTarget& target, sf::RenderStates states)
{
    for (auto& projectile : this->projectiles)
    {
        target.draw(projectile->shape);
    }
}

void Projectile::removeProjectile()
{


}


void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

Weapon* Projectile::clone()
{
    return new Projectile(*this);
}

bool Projectile::outOfBounds() const
{
    bool outOfBounds = false;
    sf::Vector2f position = this->shape.getPosition();
   
     
        if (position.y < 0.f || position.y > HEIGHT || position.x < 0.f || position.x > WIDTH)
        {
            outOfBounds = true;

        }
    
    return outOfBounds;
}

vector<shared_ptr<Projectile>> Projectile::getProjectiles() const
{
    return this->projectiles;
}

