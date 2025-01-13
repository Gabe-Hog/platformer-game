#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameObjects.h"
#include "assetHandler.h"

class Player;

using namespace std;

class Game;
class Weapon;

class Character:public GameObjects

{
private:
	string name;
	int health;
	float moveSpeed;

	Weapon* weapon;
	Game* gameInstance = nullptr;
	assetHandler<sf::Font>* fontHandler;

	sf::Text characterText;
	sf::Font nameFont = fontHandler->getAsset("nameFont");

	assetHandler<sf::Texture>* textureHandler;
	sf::Sprite characterSprite;
	sf::Texture characterTexture;
	void (Game::* onDeathCallBack)(const Player&) = nullptr;


	


protected:
	void invokeOnDeath(const Player& player);
	Weapon* getWeapon() const;

	void moveCharacterSprite(sf::Vector2f offset);

	void setNameTextPosition(sf::Vector2f pos);

	void setSpriteScale(sf::Vector2f newScale);
	void setSpriteOrigin();
	void setCharacterTexture(string keyWord);
	void setTextureToSprite();
	sf::Texture& getTexture();
	
	

public:
	Character() = default;
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, void (Game::* onDeathCallBack)(const Player&), assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Character(const Character& other);
	virtual ~Character();

	

	virtual void updatePosition(float dTime) = 0;
	
	virtual void checkForDeath() = 0;


	void takeDamage(int damage);

	float getMoveSpeed() const;
	string characterDataToString() const;
	int getHealth() const;
	sf::Text getText() const;
	string getName() const;
	sf::Vector2f getSpritePosition() const; 
	sf::FloatRect getSpriteBounds() const;


	void setSpritePosition(sf::Vector2f newPosition);
	
	void setHealth(int newHealth);
	void setMoveSpeed(float newMoveSpeed);


	virtual GameObjects* clone() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
#endif
