#include "Character.h"
#include "Weapon.h"
#include "assetHandler.h"
#include <iostream>



Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	weapon(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance(), fontHandler(fontHandler), textureHandler(textureHandler)
{
	

}

Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	weapon(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance(gameInstance), fontHandler(fontHandler), textureHandler(textureHandler)
{
	
	this->characterText.setCharacterSize(18);
	this->characterText.setFillColor(sf::Color::White);
	this->characterText.setString(this->characterToString());
	sf::FloatRect textBounds = this->characterText.getGlobalBounds();
	this->characterText.setOrigin(textBounds.left, textBounds.top + textBounds.height);
	this->characterText.setFont(this->nameFont);
}

Character::Character(const Character& other) : 
	weapon(other.weapon->clone()), health(other.health), name(other.name), moveSpeed(other.moveSpeed), fontHandler(other.fontHandler), 
	textureHandler(other.textureHandler), gameInstance(other.gameInstance), characterText(other.characterText), nameFont(other.nameFont), characterSprite(other.characterSprite)
{
}




Character::~Character()
{
	delete this->weapon;
	

}


float Character::getMoveSpeed() const
{
	return this->moveSpeed;
}

Game* Character::getGameInstancePointer() const
{
	return this->gameInstance;
}

Weapon* Character::getWeapon() const
{
	return this->weapon;
}

void Character::takeDamage(int damage)
{
	cout << this->getHealth() << endl;
	this->health -= damage;
	this->characterText.setString(this->characterToString());
}

int Character::getHealth() const
{
	return this->health;
}

string Character::getName() const
{
	return this->name;
}

string Character::characterToString() const
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
}

void Character::setMoveSpeed(float newMoveSpeed)
{
	this->moveSpeed = newMoveSpeed;
}

void Character::setTexture(string keyWord)
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

void Character::setSpriteTexture(string keyWord)
{
	this->characterTexture = this->textureHandler->getAsset(keyWord);
	this->characterSprite.setTexture(this->characterTexture);
}

sf::Sprite& Character::getReferenceToSprite() 
{
	return this->characterSprite;
}




