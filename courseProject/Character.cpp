#include "Character.h"
#include "Weapon.h"
#include "assetHandler.h"
#include <iostream>
#include "Enemy.h"




Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, void (Game::* onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	weapon(weapon), health(newHealth), name(newName), moveSpeed(newMoveSpeed), gameInstance(gameInstance), onDeathCallBack(onDeathCallBack), fontHandler(fontHandler), textureHandler(textureHandler)
{
	
	this->characterText.setCharacterSize(18);
	this->characterText.setFillColor(sf::Color::White);
	this->characterText.setString(this->characterDataToString());
	sf::FloatRect textBounds = this->characterText.getGlobalBounds();
	this->characterText.setOrigin(textBounds.left, textBounds.top + textBounds.height);
	this->characterText.setFont(this->nameFont);
}






Character::~Character()
{
	delete this->weapon;
}


float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}



void Character::invokeOnDeath(const Player& player)
{
	(this->gameInstance->*onDeathCallBack)(player);
}

Weapon* Character::getWeapon() const
{
	return this->weapon;
}

void Character::moveCharacterSprite(sf::Vector2f offset)
{
	this->characterSprite.move(offset);
}

void Character::setSpriteScale(sf::Vector2f newScale)
{
	this->characterSprite.setScale(newScale);
}



void Character::setSpriteOrigin()
{
	sf::FloatRect bounds = this->characterSprite.getLocalBounds();

	this->characterSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

sf::Vector2f Character::getSpritePosition() const
{
	return this->characterSprite.getPosition();
}

sf::FloatRect Character::getSpriteBounds() const
{
	return this->characterSprite.getGlobalBounds();
}

void Character::setSpritePosition(sf::Vector2f newPosition)
{
	this->characterSprite.setPosition(newPosition);
}




void Character::takeDamage(int damage)
{
	
	this->health -= damage;
	this->characterText.setString(this->characterDataToString());
}

int Character::getHealth() const
{
	return this->health;
}

string Character::getName() const
{
	return this->name;
}

string Character::characterDataToString() const
{
	return this->name + ": " + to_string(this->health) + " HP";
}

void Character::setNameTextPosition(sf::Vector2f pos)
{
	this->characterText.setPosition(pos);
}

sf::Text Character::getText() const
{
	return this->characterText;
}



void Character::setHealth(int newHealth)
{
	this->health = newHealth;
	this->characterText.setString(this->characterDataToString());
}

void Character::setMoveSpeed(float newMoveSpeed)
{
	this->moveSpeed = newMoveSpeed;
}

void Character::setCharacterTexture(string keyWord)
{
	try
	{
		this->characterTexture = this->textureHandler->getAsset(keyWord);
	}
	catch (out_of_range e)
	{
		cout << e.what() << endl;
	}
}

void Character::setTextureToSprite()
{
	this->characterSprite.setTexture(this->characterTexture);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->characterSprite);

	target.draw(this->getText());
	this->getWeapon()->draw(target, states);
}

sf::Texture& Character::getTexture()
{
	return this->characterTexture;
}

