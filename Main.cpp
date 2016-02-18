/**
 *	This is a text-only battle game loosely based off the battle system in Pokemon
 *	(one of my favorite games). It is a project I am using to help learn OOP in C++
 *	and have fun doing so! It is a work in progress.
 *
 *	To do List:
 *	Allow uppercase characters
 *	Allow user to choose which enemy to face (eg. dragon or fish)
 *	Give user option to restart game after it ends
 *	Create stat changing abillities
 *	Allow user to choose which type of enemy to face
 *	Add a "help" command to give the user information
 *	Make waiting increase energy
 *	Make it so that enemies don't use abillities they don't have energy for (or make them never run out)
 *	Make wait a command that is included in the abilities menu
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#include "Character.h"
#include "Ability.h"
#include "Fish.h"
#include "Dragon.h"
#include "Protagonist.h"

bool isValidAction(string action);
void doUserCommand(string action, Character *actionTaker, Character *receiver);
void setUpTypeMatchups();
double getMultiplier(int attacker, int defender);

//An enum containing all the Type. The last element is the number of Type in the enum,
//used for the type match-up array

enum Type {
	NORMAL, FIRE, WATER, GRASS, NUM_OF_TYPES
};


//The array of type matchups. The value in a cell (x,y) is the multiplier when type
//x attacks type y. For example, fire deals double damage to grass but only half damage
//to water, so typeMatchups[FIRE][GRASS] = 2.0 and typeMatchups[FIRE][WATER] = 0.5
static double typeMatchups[NUM_OF_TYPES][NUM_OF_TYPES];

int main() {
	//Make sure the type matchups array is set up
	setUpTypeMatchups();
	cout << "Welcome to the game! When using commands in the game, please use lowercase only.\n";
	cout << "Uppercase will be allowed in future versions (hopefully)\n";

	//Create the character that the user uses
	string userName;
	cout << "What would you like to name your character?\n";
	cin >> userName;

	Protagonist User(userName);

	//Create an enemy character, for now it's a dragon
	Dragon Enemy(20);
	cout << "You face a mighty dragon!\n";
	//Keep the game going until one character dies
	while (!User.getIsDead() && !Enemy.getIsDead()) {

		string action;

		//First, the user takes an action
		do {
			cout << "Please choose to attack or wait\n";

			cin >> action;
		} while (!isValidAction(action));

		doUserCommand(action, &User, &Enemy);
		if (User.getIsDead() || Enemy.getIsDead()) {
			break;
		}
		cout << "\n";

		//Enemy's turn to take an action
		Enemy.doAction(&User);
	}

	//Check if the user has died (loss) or not (win)
	//Note: in the case where both characters die (not possible currently),
	//it will be a loss
	if (User.getIsDead()) {
		cout << User.getName() << " died! " << User.getName() << " lost!\n";
	}

	else {
		cout << Enemy.getName() << " died! " << User.getName() << " won!\n";

	}

	return 0;
}

/*
 * Checks if an action is one of the valid actions
 *
 * Note: Change this function as more actions are added!
 *
 * Returns true if action is valid, false otherwise
 */

bool isValidAction(string action) {

	if (action == "attack" || action == "wait") {
		return true;
	}

	return false;

}

/*
 * Executes a given action for the user
 * When this function finishes executing, the action given will have been finished
 *
 * @param action, the action being executed
 * 		  actionTaker, the Character doing the action
 * 		  receiver, the Character on the receiving end of the action
 */
void doUserCommand(string action, Character *actionTaker, Character *receiver) {

	if (action == "attack") {

		set<string> abilityNames = actionTaker->getAbilityNames();
		string inputAbilityName;

		do {
			cout << "Choose an attack (current energy is "
					<< actionTaker->getEnergy() << ")\n";
			actionTaker->printAbilities();
			cin >> inputAbilityName;
		} while (abilityNames.find(inputAbilityName) == abilityNames.end());

		Ability inputAbility = actionTaker->getAbilityFromName(
				inputAbilityName);

		cout << actionTaker->getName() << " used " << inputAbilityName << "\n";

		double multiplier =
				typeMatchups[inputAbility.getType()][receiver->getType()];

		inputAbility.doAbility(actionTaker, receiver, multiplier);

	} else if (action == "wait") {

		//Make something that increases energy here

		cout << actionTaker->getName() << " just waited\n";
	}

}

void setUpTypeMatchups() {

	//First make each match-up a 1
	for (int row = 0; row < NUM_OF_TYPES; row++) {
		for (int col = 0; col < NUM_OF_TYPES; col++) {

			typeMatchups[row][col] = 1.0;
		}
	}

	//Normal is not weak or strong against any type

	//Fire is strong against grass
	typeMatchups[FIRE][GRASS] = 2.0;

	//Fire is weak against water and fire
	typeMatchups[FIRE][WATER] = 0.5;
	typeMatchups[FIRE][FIRE] = 0.5;

	//Water is strong against fire
	typeMatchups[WATER][FIRE] = 2.0;

	//Water is weak against grass and water
	typeMatchups[WATER][GRASS] = 0.5;
	typeMatchups[WATER][WATER] = 0.5;

	//Grass is strong against water
	typeMatchups[GRASS][WATER] = 2.0;

	//Grass is weak against fire and grass
	typeMatchups[GRASS][FIRE] = 0.5;
	typeMatchups[GRASS][GRASS] = 0.5;

}

double getMultiplier(int attacker, int defender) {
	return typeMatchups[attacker][defender];
}

