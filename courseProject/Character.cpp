#include "Character.h"
#include "Weapon.h"
#include "assetHandler.h"
#include <iostream>
#include "Monster.h"



Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	weapon(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance(), fontHandler(fontHandler), textureHandler(textureHandler)
{
	this->setBounds(characterSprite);
	sf::FloatRect bounds = this->characterSprite.getLocalBounds();
	this->characterSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
	this->characterText.setCharacterSize(18);
	this->characterText.setFillColor(sf::Color::White);
	this->characterText.setString(this->characterToString());
	this->characterText.setFont(this->nameFont);
}

Character::Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler) :
	weapon(weapon), health(newHealth), moveSpeed(newMoveSpeed), name(newName), gameInstance(gameInstance), fontHandler(fontHandler), textureHandler(textureHandler)
{
	this->setBounds(characterSprite);
	
	this->characterText.setCharacterSize(18);
	this->characterText.setFillColor(sf::Color::White);
	this->characterText.setString(this->characterToString());
	sf::FloatRect textBounds = this->characterText.getGlobalBounds();
	this->characterText.setOrigin(textBounds.left, textBounds.top + textBounds.height);
	this->characterText.setFont(this->nameFont);
}

Character::Character(const Character& other) : 
	weapon(other.weapon->clone()), health(other.health), name(other.name), moveSpeed(other.moveSpeed), fontHandler(other.fontHandler), 
	textureHandler(other.textureHandler), gameInstance(other.gameInstance), characterText(other.characterText), nameFont(other.nameFont), 
	characterSprite(other.characterSprite), characterTexture(other.characterTexture)
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

void Character::moveCharacterSprite(sf::Vector2f offset)
{
	this->characterSprite.move(offset);
}

void Character::setSpriteScale(sf::Vector2f newScale)
{
	this->characterSprite.setScale(newScale);
}

void Character::setSpriteBounds()
{
	this->setBounds(this->characterSprite);
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

void Character::setSpritePosition(sf::Vector2f newPosition)
{
	this->characterSprite.setPosition(newPosition);
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

void Character::assignTexture()
{
	this->characterSprite.setTexture(this->characterTexture);
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->characterSprite);
	sf::CircleShape originMarker(5); 
	originMarker.setFillColor(sf::Color::Red);
	originMarker.setPosition(characterSprite.getPosition());
	target.draw(originMarker);
	target.draw(this->getText());
	this->getWeapon()->callDraw(target, states);
}

sf::Texture& Character::getTexture()
{
	return this->characterTexture;
}

