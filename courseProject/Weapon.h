#ifndef WEAPON_H
#define WEAPON_H

class Weapon
{
private:
	int damage = 1;



public:
	Weapon() = default;
	Weapon(int damage);
	virtual ~Weapon();
	virtual void attack() = 0;
	void dealDamage();

};
#endif