#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "GameObjects.h"
#include "Weapon.h"


using namespace std;

class Character:public GameObjects
{
private:
	int health;
	string name;
	Weapon* wep;
	float moveSpeed;
	sf::FloatRect bounds;

public:
	Character() = default;
	Character(Weapon* weapon, int newHealth, string newName, float newMoveSpeed);
	~Character();
	void setBounds(const sf::Shape& shape); 
	sf::FloatRect getBounds();
	float getMoveSpeed() const;
	virtual void updatePosition(float dTime) = 0;
	void calcHealth();


};
#endif
