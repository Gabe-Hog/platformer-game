#include "Player.h"
#include "Game.h"
#include <math.h>
#include <iostream>


Player::Player(void(Game::*deathCallBack)(const Player&), Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	Character(new Sword(textureHandler->getAsset("sword")), 5, "Bob", 200.f, gameInstance, fontHandler, textureHandler), deathCallBack(deathCallBack), position(25, 525)
{

	this->setSpriteTexture("chick");
	playerSprite = getReferenceToSprite();
	this->playerSprite.setPosition(position);
	sf::FloatRect bounds = this->playerSprite.getLocalBounds();
	playerSprite.setOrigin(bounds.width/2.f, bounds.height/2.f);
	this->playerSprite.setScale(0.019f, 0.02f);
	this->setBounds(playerSprite);
	this->setNameTextPosition({ 0.f, 0.f });

}

Player::Player(const Player& other) : Character(other), score(other.score), playerSprite(other.playerSprite),position(other.position), 
velocity(other.velocity), jumpHeight(other.jumpHeight), isJumping(other.isJumping), deathCallBack(other.deathCallBack)
{
}

Player::~Player()
{
	
}

void Player::updatePosition(float dTime)
{
	
	
	this->setBounds(this->playerSprite);
	this->getWeapon()->setOwnerPosition(this->getPlayerPosition());
	
	
	sf::FloatRect playerArea = this->getBounds();
	this->velocity.x = 0.f;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->velocity.x += this->getMoveSpeed();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		this->velocity.x -= this->getMoveSpeed();

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		this->getWeapon()->attack();
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isJumping)
	{
		this->isJumping = true;
		velocity.y = -sqrtf(2.0f * 981.f * this->jumpHeight);
		

	}
	

	this->getWeapon()->updatePosition(dTime);
	this->velocity.y += 981.f * dTime;
	this->playerSprite.move(velocity * dTime);
	this->checkForDeath();


}

bool Player::checkCollision(GameObjects& object1)
{
	bool collisionMonster = false;
	sf::FloatRect playerBounds = this->getBounds();

	if (playerSprite.getPosition().x - playerBounds.width/2.f < 0.f)
	{
		playerSprite.setPosition(playerBounds.width/2.f, playerSprite.getPosition().y);
	}

	if (playerSprite.getPosition().x + playerBounds.width/2 > WIDTH)
	{
		playerSprite.setPosition(WIDTH - playerBounds.width/2, playerSprite.getPosition().y);
	}

	if (playerSprite.getPosition().y + playerBounds.height/2 > HEIGHT)
	{
		
		playerSprite.setPosition(playerSprite.getPosition().x, HEIGHT - playerBounds.height/2);
		this->isJumping = false;
	}

	if (playerSprite.getPosition().y/2 < 0.f)
	{
		
		playerSprite.setPosition(playerSprite.getPosition().x, 0.f);
		
	}

	this->getWeapon()->checkCollision(object1);
	



	return collisionMonster;
}

void Player::setJumping(bool state)
{
	this->isJumping = state;
}

void Player::setVelocity(sf::Vector2f newVel)
{
	this->velocity = newVel;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*sf::FloatRect bounds = playerSprite.getGlobalBounds();
	sf::RectangleShape boundingBox(sf::Vector2f(bounds.width, bounds.height));
	boundingBox.setPosition(bounds.left, bounds.top);
	boundingBox.setFillColor(sf::Color::Transparent);
	boundingBox.setOutlineColor(sf::Color::Red);
	boundingBox.setOutlineThickness(1.f);
	sf::CircleShape originMarker(2.f);
	originMarker.setFillColor(sf::Color::Green);
	originMarker.setPosition(playerSprite.getPosition().x - 2, playerSprite.getPosition().y - 2);
	target.draw(originMarker);
	target.draw(boundingBox);*/
	target.draw(this->playerSprite);
	target.draw(this->getText());
	this->getWeapon()->callDraw(target, states);
}

GameObjects* Player::clone()
{
	return new Player(*this);
}


int Player::getScore() const
{
	return this->score;
}

string Player::getStats() const
{
	return this->getName() + " " + to_string(this->score) + " ";
}

sf::Sprite* Player::getPlayer()
{
	return &this->playerSprite;
}

sf::Vector2f Player::getVelocity() const
{
	return this->velocity;
}

void Player::updateScore()
{
	this->score++;
	cout << "Player Score: " << this->score << endl;
}

sf::Vector2f Player::getPlayerPosition() const
{
	return this->playerSprite.getPosition();
}

void Player::checkForDeath()
{
	if (this->getHealth() <= 0)
	{
		
		(this->getGameInstancePointer()->*deathCallBack)(*this);
	}



}


