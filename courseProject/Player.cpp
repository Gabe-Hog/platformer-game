#include "Player.h"

Player::Player() : Character(new Sword())
{
}

void Player::move()
{
}

int Player::getScore() const
{
	return this->score;
}

void Player::updateScore()
{
	this->score++;
}
