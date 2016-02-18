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
#include "Main.h"


using namespace std;

#ifndef CHARACTER_H_
#define CHARACTER_H_



class Character {
public:

	enum Type {
		NORMAL, FIRE, WATER, GRASS, NUM_OF_TYPES
	};
	Character();

	virtual ~Character();

	Character(int level, int attack, int defense, int health, int energy,
			string name, int characterType);
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
	int getType() const;
	void doAction(Character *target);

protected:
	int level;
	int attack;
	int defense;
	int health;
	int energy;
	bool isDead;
	string name;
	vector<Ability> abilities;
	int characterType;
};

#endif /* CHARACTER_H_ */
