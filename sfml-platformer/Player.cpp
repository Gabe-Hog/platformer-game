#include "Player.h"
#include "Game.h"
#include <math.h>
#include <iostream>



Player::Player(Game* gameInstance, void(Game::* onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler):
	Character(new Sword(textureHandler->getAsset("sword")), 5, "Bob", 200.f, gameInstance, onDeathCallBack, fontHandler, textureHandler)
{
	const sf::Vector2f TEXT_POSITION = { 0.f, 0.f };
	const sf::Vector2f Start_POSITION = { 25.f, 525.f };
	const sf::Vector2f SPRITE_SCALE = { 0.019f, 0.02f };

	this->setCharacterTexture("chick");
	this->setTextureToSprite();
	this->setSpriteScale(SPRITE_SCALE);
	this->setSpritePosition(Start_POSITION);
	this->setSpriteOrigin();

	this->setNameTextPosition(TEXT_POSITION);
}

Player::~Player()
{
	
}


void Player::movePlayer(float dTime)
{
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
	this->decreaseVelocityY(dTime);
	this->moveCharacterSprite(velocity * dTime);
}

void Player::decreaseVelocityY(float dTime)
{
	static const float GRAVITY = 981.f;
	this->velocity.y += GRAVITY * dTime;
}


void Player::updatePosition(float dTime)
{
	this->getWeapon()->setOwnerPosition(this->getSpritePosition());
	this->movePlayer(dTime);
	this->getWeapon()->updatePosition(dTime);
}

void Player::checkCollision(GameObjects& object)
{
	
	sf::FloatRect playerBounds = this->getSpriteBounds();
	sf::Vector2f playerPosition = this->getSpritePosition();

	if (playerPosition.x - playerBounds.width / 2.f < 0.f)
	{
		this->setSpritePosition({ playerBounds.width / 2.f, playerPosition.y});
	}

	if (playerPosition.x + playerBounds.width/2 > WIDTH)
	{
		this->setSpritePosition({ WIDTH - playerBounds.width / 2.f, playerPosition.y });
	}

	if (playerPosition.y + playerBounds.height/2.f > HEIGHT)
	{
		
		this->setSpritePosition({ playerPosition.x, HEIGHT - playerBounds.height / 2.f });
		
	}

	if (playerPosition.y / 2.f < 0.f)
	{

		this->setSpritePosition({playerPosition.x, 0.f});
		this->isJumping = false;
		
	}

	this->getWeapon()->checkCollision(object);
}


void Player::setJumping(bool state)
{
	this->isJumping = state;
}

void Player::setVelocity(sf::Vector2f newVel)
{
	this->velocity = newVel;
}

int Player::getScore() const
{
	return this->score;
}

string Player::getStats() const
{
	return this->getName() + " " + to_string(this->score) + " ";
}



sf::Vector2f Player::getVelocity() const
{
	return this->velocity;
}

void Player::updateScore()
{
	this->score++;
	
}


void Player::checkForDeath()
{
	if (this->getHealth() <= 0)
	{
		this->invokeOnDeath(*this);
	}
}
