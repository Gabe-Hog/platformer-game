#include "Projectile.h"
#include "Player.h"
#include "Platform.h"
#include "Game.h"
#include <algorithm>

Projectile::Projectile(int damage, float speed) : Weapon(damage, speed)
{
    
    
}

Projectile::Projectile(float speed, sf::Vector2f ownerPosition, sf::Vector2f targetPosition) : Weapon(speed), targetPosition(targetPosition)
{
    this->shape.setOrigin(this->shape.getRadius(), this->shape.getRadius());
    this->shape.setFillColor(sf::Color::White);
    this->shape.setPosition(ownerPosition);
}



void Projectile::attack(sf::Vector2f targetDirection)
{
    sf::Vector2f test = this->getOwnerPosition();
    this->projectiles.push_back(make_shared<Projectile>(this->getSpeed(), this->getOwnerPosition(), targetDirection));
    
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
        projectile->shape.move(projectile->getNormalizedDirection() * projectile->getSpeed() * dTime);
        projectile->isMoving = true;
     
       
    }
    projectiles.erase(remove_if(projectiles.begin(), projectiles.end(),
        [](const shared_ptr<Projectile>& projec) {return projec->outOfBounds() || projec->hit();
        }),
    projectiles.end());

  
}

void Projectile::checkCollision(GameObjects& object)
{
   
    for (auto& projectile : this->projectiles)
    
    {
        
        if (Player* player = dynamic_cast<Player*>(&object))
        {

            if (player->getSpriteBounds().contains(projectile->shape.getPosition()))
            {
          
                this->dealDamage(*player);
                projectile->setDidHit(true);
            }
        }

        else if (Platform* platform = dynamic_cast<Platform*>(&object))
        {
            sf::FloatRect platformBounds = platform->getBounds();
            if (platformBounds.contains(projectile->shape.getPosition()))
            {
                
                projectile->setDidHit(true);
               
            }

        }

        
    }


}


void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for (auto& projectile : this->projectiles)
    {
        target.draw(projectile->shape);
    }
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

