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


	


protected:
	Game* getGameInstancePointer() const;
	virtual void checkForDeath() = 0;
	Weapon* getWeapon() const;
	void moveCharacterSprite(sf::Vector2f offset);
	void setSpriteScale(sf::Vector2f newScale);
	void setSpriteBounds();
	void setSpriteOrigin();




public:
	Character() = default;
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed, Game* gameInstance, assetHandler<sf::Font>* fontHandler, assetHandler<sf::Texture>* textureHandler);
	Character(const Character& other);
	virtual ~Character();
	sf::Vector2f getSpritePosition() const; 
	void setSpritePosition(sf::Vector2f newPosition);
	float getMoveSpeed() const;
	virtual void updatePosition(float dTime) = 0;
	void takeDamage(int damage);
	int getHealth() const;
	string getName() const;
	string characterToString() const;
	sf::Text getText() const;
	void setNameTextPosition(sf::Vector2f pos);
	void setHealth(int newHealth);
	void setMoveSpeed(float newMoveSpeed);
	sf::Texture& getTexture();
	void setCharacterTexture(string keyWord);
	void assignTexture();
	virtual GameObjects* clone() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};
#endif
