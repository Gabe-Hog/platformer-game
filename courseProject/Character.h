#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameObjects.h"
#include "Movable.h"
#include "assetHandler.h"


using namespace std;

class Game;
class Weapon;

class Character:public GameObjects

{
private:
	int health;
	string name;
	Weapon* weapon;
	float moveSpeed;
	Game* gameInstance = nullptr;
	assetHandler<sf::Font>* fontHandler;
	sf::Text characterText;
	sf::Font nameFont = fontHandler->getAsset("nameFont");
	assetHandler<sf::Texture>* textureHandler;
	/*sf::Sprite characterSprite;*/
	sf::Texture characterTexture;
	

public:
	Character() = default;
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Character(const Character& other);
	virtual ~Character();
	
	
	float getMoveSpeed() const;
	virtual void checkForDeath() = 0;
	Game* getGameInstancePointer() const;
	virtual void updatePosition(float dTime) = 0;
	Weapon* getWeapon() const;
	void takeDamage(int damage);
	int getHealth() const;
	string getName() const;
	string characterToString() const;
	void setNameTextPosition(sf::Vector2f pos);
	sf::Text getText() const;
	void setHealth(int newHealth);
	void setMoveSpeed(float newMoveSpeed);
	sf::Texture& getTexture();
	void setCharacterTexture(string keyWord);
	/*sf::Sprite& getReferenceToSprite();*/
	virtual GameObjects* clone() = 0;
	

};
#endif
