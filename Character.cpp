/**
 * The Character class
 *
 * A character has multiple stats and is considered "dead" if health hits 0
 */

#include "Character.h"
#include <stdlib.h>
#include <time.h>

/*
 * Constructor
 */
Character::Character() {

}

/*
 * Destructor
 */
Character::~Character() {

}

/*
 * Constructor
 */
Character::Character(int level, int attack, int defense, int health, int energy,
		string name, int characterType) {

	this->level = level;
	this->attack = attack;
	this->defense = defense;
	this->health = health;
	this->energy = energy;
	this->isDead = false;
	this->name = name;
	Ability Punch(0, 5, "punch", NORMAL);

	abilities.push_back(Punch);

	this->characterType = characterType;

}
/*
 * Multiple observer methods
 */
int Character::getLevel() const {
	return level;
}

int Character::getAttack() const {
	return attack;
}

int Character::getDefense() const {
	return defense;
}

int Character::getHealth() const {
	return health;
}

int Character::getEnergy() const {
	return energy;
}

bool Character::getIsDead() const {
	return isDead;
}

string Character::getName() const {
	return name;
}

int Character::getType() const {
	return characterType;
}

/*
 * This function should be called when the character receives damage
 */
void Character::takeDamage(int damage) {

	if (health <= damage) {
		health = 0;
		isDead = true;
	} else {
		health -= damage;
	}
}

/*
 * This function should be called when the user loses energy. Does not allow energy
 * to become negative and instead makes the value 0 is loss>energy
 */
void Character::loseEnergy(int loss) {

	energy -= loss;
	if (energy < 0) {
		energy = 0;
	}
}

/*
 * Prints out the abilities of the character, one on each line, with a dash in front
 * of each ability
 */
void Character::printAbilities() {
	vector<Ability>::iterator it;
	for (it = abilities.begin(); it != abilities.end(); it++) {
		Ability a = *it;
		cout << "-" << a.getName() << " (cost: "<< a.getCost() << ")\n";
	}
}

/*
 * Returns a set of the names of every ability this character has
 */
set<string> Character::getAbilityNames() {
	set<string> returnSet;
	vector<Ability>::iterator it;
	for (it = abilities.begin(); it != abilities.end(); it++) {
		Ability a = *it;
		returnSet.insert(a.getName());
	}
	return returnSet;
}

/*
 * Given a string, returns an ability with that name
 *
 * Precondition: the name given is an ability the character has
 */
Ability Character::getAbilityFromName(string abilityName) {

	Ability a;
	vector<Ability>::iterator it;
	for (it = abilities.begin(); it != abilities.end(); it++) {
		a = *it;
		if (a.getName() == abilityName) {
			return a;
		}
	}
	return a;
}

/*
 * Returns a random ability that the character has
 */
Ability Character::getRandomAbility() const {
	srand(time(NULL));
	int randomNum = rand() % abilities.size();

	return abilities.at(randomNum);
}

void Character::doAction(Character *target) {
	Ability randomAbility = getRandomAbility();
	cout << getName() << " used " << randomAbility.getName() << "\n";
	double multiplier = getMultiplier(randomAbility.getType(),target->getType());
	randomAbility.doAbility(this, target, multiplier);
	cout << "\n";

}
