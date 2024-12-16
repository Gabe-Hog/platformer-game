#include "Player.h"
#include "Game.h"
Player::Player() : 
	Character(new Sword(), 5, "Bob", 0.05f), position(100, 300), player(sf::Vector2f(50,50))
{
	player.setFillColor(sf::Color::Red);
	player.setPosition(position);
}

Player::~Player()
{
}

void Player::updatePosition()
{
	sf::FloatRect playerArea = this->player.getGlobalBounds();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && playerArea.left + playerArea.width <= WIDTH)
	{
		
		this->player.move(this->getMoveSpeed(), 0);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && playerArea.left >= 0.0f)
	{

		this->player.move(-this->getMoveSpeed(), 0);

	}





}

bool Player::checkCollision()
{
	return false;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->player);
}

int Player::getScore() const
{
	return this->score;
}

void Player::updateScore()
{
	this->score++;
}
