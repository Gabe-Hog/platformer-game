#include "Player.h"
#include "Game.h"
#include <math.h>
#include <iostream>
Player::Player() :
	Character(new Sword(), 5, "Bob", 200.f), position(25, 525), player(sf::Vector2f(50, 50))
{
	
	player.setFillColor(sf::Color::Red);
	player.setPosition(position);
	player.setOrigin(player.getSize().x/2, player.getSize().y/2);
	this->setBounds(player);
}

Player::Player(void(Game::*deathCallBack)(const Player&), Game* gameInstance) : Character(new Sword(), 1, "Bob", 200.f, gameInstance), deathCallBack(deathCallBack), position(25, 525), player(sf::Vector2f(50, 50))
{
	player.setFillColor(sf::Color::Red);
	player.setPosition(position);
	player.setOrigin(player.getSize().x / 2, player.getSize().y / 2);
	this->setBounds(player);
}

Player::~Player()
{
	
}

void Player::updatePosition(float dTime)
{
	
	this->setBounds(this->player);
	this->getWeapon()->setOwnerPosition(player.getPosition());
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
	this->player.move(velocity * dTime);
	this->checkForDeath();


}

bool Player::checkCollision(GameObjects& object1)
{
	bool collisionMonster = false;
	sf::FloatRect playerbounds = this->getBounds();

	if (player.getPosition().x - playerbounds.width/2 < 0.f)
	{
		player.setPosition(player.getOrigin().x, player.getPosition().y);
	}

	if (player.getPosition().x + playerbounds.width/2 > WIDTH)
	{
		player.setPosition(WIDTH - playerbounds.width/2, player.getPosition().y);
	}

	if (player.getPosition().y + playerbounds.height/2 > HEIGHT)
	{
		this->isJumping = false;
		player.setPosition(player.getPosition().x, HEIGHT - playerbounds.height/2);
	}

	if (player.getPosition().y/2 < 0.f)
	{
		
		player.setPosition(player.getPosition().x, 0.f);
		
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
	target.draw(this->player);
	this->getWeapon()->callDraw(target, states);
}

//void Player::operator = (Player& other)
//{
//	if (this != &other)
//	{
//
//		delete this->getWeapon();
//		this->score = other.score;
//		this->position = other.position;
//		this->velocity = other.velocity;
//		this->player = other.player;
//	
//	}
//
//
//}

int Player::getScore() const
{
	return this->score;
}

string Player::getStats() const
{
	return this->getName() + " " + to_string(this->score) + " ";
}

sf::Shape* Player::getPlayer()
{
	return &this->player;
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
	return this->player.getPosition();
}

void Player::checkForDeath()
{
	if (this->getHealth() <= 0)
	{
		
		(this->getGameInstancePointer()->*deathCallBack)(*this);
	}



}


