/*
 * Character.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Jhajj
 */
#include <iostream>
#include <string>

using namespace std;

#ifndef CHARACTER_H_
#define CHARACTER_H_

class Character {
public:
	Character();
	virtual ~Character();

	Character(int,int,int,int,int,string);
	int getLevel() const;
	int getAttack() const;
	int getDefense() const;
	int getHealth() const;
	int getEnergy() const;
	bool getIsDead() const;
	void takeDamage(int);
	string getAction();
	string getName() const;

private:
	int level;
	int attack;
	int defense;
	int health;
	int energy;
	bool isDead;
	string name;
	//Type Type;
};

#endif /* CHARACTER_H_ */
