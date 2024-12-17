#include "Player.h"
#include "Game.h"
#include <math.h>
#include <iostream>
Player::Player() : 
	Character(new Sword(), 5, "Bob", 50.f), position(0, 550), player(sf::Vector2f(50,50))
{
	
	player.setFillColor(sf::Color::Red);
	player.setPosition(position);
	this->setBounds(player);
}

Player::~Player()
{
	
}

void Player::updatePosition(float dTime)
{
	this->setBounds(this->player);
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

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isJumping)
	{
		this->isJumping = true;
		velocity.y = -sqrtf(2.0f * 981.f * this->jumpHeight);
		cout << "Jump" << endl;

	}
	

	this->velocity.y += 981.f * dTime;
	this->player.move(velocity * dTime);
	


}

bool Player::checkCollision(GameObjects& object1)
{
	bool collisionMonster = false;
	sf::FloatRect playerbounds = this->getBounds();

	if (player.getPosition().x  < 0.f)
	{
		player.setPosition(0.f, player.getPosition().y);
	}

	if (player.getPosition().x + playerbounds.width > WIDTH)
	{
		player.setPosition(WIDTH - playerbounds.width, player.getPosition().y);
	}

	if (player.getPosition().y + playerbounds.height > HEIGHT)
	{
		this->isJumping = false;
		player.setPosition(player.getPosition().x, HEIGHT - playerbounds.height);
	}

	if (player.getPosition().y < 0.f)
	{
		
		player.setPosition(player.getPosition().x, 0.f);
		
	}

	




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
}

int Player::getScore() const
{
	return this->score;
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
}
