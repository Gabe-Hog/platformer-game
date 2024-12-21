#include "Projectile.h"
#include "Character.h"
#include "Platform.h"
#include "Game.h"

#include "iostream"
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

Projectile::~Projectile()
{
    for (auto& projectile : this->projectiles)
    {
        delete projectile;
    }
}

void Projectile::attack(sf::Vector2f targetDirection)
{
    sf::Vector2f test = this->getOwnerPosition();
    this->projectiles.push_back(new Projectile(this->speed, this->getOwnerPosition(), targetDirection));
    
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
                cout << "did Collide" << endl;
                delete projectile;
                this->dealDamage(*character);
            }
        }
        else if (Platform* platform = dynamic_cast<Platform*>(&object1))
        {
            sf::FloatRect platformBounds = platform->getBounds();
            if (platformBounds.intersects(projectile->getBounds()))
            {
                cout << "Collided Platform" << endl;
                delete projectile;
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


bool Projectile::hit()
{
    return false;
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    
}

bool Projectile::outOfBounds() const
{
    bool outOfBounds = false;
    sf::Vector2f position;
   
     position = shape.getPosition();
        if (position.y < 0.f || position.y > HEIGHT || position.x < 0.f || position.x > WIDTH)
        {
            delete this;
            outOfBounds = true;
        }
    
    return outOfBounds;
}

vector<Projectile*> Projectile::getProjectiles() const
{
    return this->projectiles;
}

