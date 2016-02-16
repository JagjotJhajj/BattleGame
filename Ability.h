/*
 * Ability.h
 *
 *  Created on: Feb 14, 2016
 *      Author: Jhajj
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef ABILITY_H_
#define ABILITY_H_


class Character;
class Ability {
public:

	virtual ~Ability();

	Ability(int cost, int power, string name);



	int getPower() const;

	string getName() const;

	int getCost() const;
	void doAbility(Character *user, Character *receiver);

	void setStatusChange(string stat, bool affectUser, int change, int multiplier);


private:
	int cost;
	int power;
	string name;
	bool isStatChanger;
	string stat;
	bool affectUser;
	int change;
	int multiplier;
};

#endif /* ABILITY_H_ */
