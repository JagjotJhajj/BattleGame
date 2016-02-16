/*
 * Character.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Jhajj
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Ability.h"

using namespace std;

#ifndef CHARACTER_H_
#define CHARACTER_H_


class Character {
public:
	virtual ~Character();

	Character(int,int,int,int,int,string);
	int getLevel() const;
	int getAttack() const;
	int getDefense() const;
	int getHealth() const;
	int getEnergy() const;
	bool getIsDead() const;
	void takeDamage(int);
	string getName() const;
	void loseEnergy(int);
	void printAbilities();
	Ability getAbilityFromName(string abilityName);
	Ability getRandomAbility() const;
	set<string> getAbilityNames();


private:
	int level;
	int attack;
	int defense;
	int health;
	int energy;
	bool isDead;
	string name;
	vector<Ability> abilities;
};

#endif /* CHARACTER_H_ */
