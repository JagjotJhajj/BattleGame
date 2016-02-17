/**
 *	This is a text-only battle game loosely based off the battle system in Pokemon
 *	(one of my favorite games). It is a project I am using to help learn OOP in C++
 *	and have fun doing so! It is a work in progress.
 *
 *	To do List:
 *	Make a Character class (x)
 *	Make an Ability class (x)
 *	Give the user ability to attack (x)
 *	Allow uppercase characters ( )
 *	Make the game winnable and loseable (x)
 *	Show ability costs ( )
 *	Create different attack and character Type (eg. fire, water, grass) (x)
 *	Allow characters to "level up" ( )
 *	Create multiple abilities, including stat changers ( )
 *	Extend Character class into multiple different character Type for enemies ( )
 *	Allow user to choose which type of enemy to face ( )
 *	Add a "help" command to give the user information ( )
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

#include "Character.h"
#include "Ability.h"




bool isValidAction(string action);
void doUserAction(string action, Character *actionTaker, Character *receiver);
void setUpTypeMatchups();
enum Type {NORMAL, FIRE, WATER, GRASS, NUM_OF_TYPES};


//An enum containing all the Type. The last element is the number of Type in the enum,
//used for the type match-up array

//The array of type matchups
double typeMatchups[NUM_OF_TYPES][NUM_OF_TYPES];


int main() {

	setUpTypeMatchups();
	//Create the character that the user uses
	Character Protagonist(5, 10, 2, 1000, 100, "Your character", FIRE);

	//Create an enemy character
	Character Enemy(2, 3, 1, 500, 50000, "McEvil",WATER);

	cout
			<< "Welcome to the game! When using commands in the game, please\nuse lowercase only. Uppercase will be allowed in future versions (hopefully)\n";

	//Keep the game going until one character dies
	while (!Protagonist.getIsDead() && !Enemy.getIsDead()) {

		string action;

		//First, the user takes an action
		do {
			cout << "Please choose to attack or wait\n";

			cin >> action;
		} while (!isValidAction(action));

		doUserAction(action, &Protagonist, &Enemy);
		if (Protagonist.getIsDead() || Enemy.getIsDead()) {
			break;
		}
		cout << "\n";

		//Enemy's turn to take an action
		Ability randomAbility = Enemy.getRandomAbility();
		double multiplier = typeMatchups[randomAbility.getType()][Protagonist.getType()];
		randomAbility.doAbility(&Enemy, &Protagonist, multiplier);
		cout << "\n";
	}

	//Check if the user has died (loss) or not (win)
	//Note: in the case where both characters die (not possible currently),
	//it will be a loss
	if (Protagonist.getIsDead()) {
		cout << Protagonist.getName() << " died! " << Protagonist.getName()
				<< " lost!\n";
	}

	else {
		cout << Enemy.getName() << " died! " << Protagonist.getName()
				<< " won!\n";

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
void doUserAction(string action, Character *actionTaker, Character *receiver) {

	if (action == "attack") {

		set<string> abilityNames = actionTaker->getAbilityNames();
		string inputAbilityName;

		do {
			cout << "Choose an attack (current energy is "
					<< actionTaker->getEnergy() << ")\n";
			actionTaker->printAbilities();
			cin >> inputAbilityName;
		} while (abilityNames.find(inputAbilityName) == abilityNames.end());

		Ability inputAbility = actionTaker->getAbilityFromName(inputAbilityName);

		cout << actionTaker->getName() << " used " << inputAbilityName << "\n";

		double multiplier = typeMatchups[inputAbility.getType()][receiver->getType()];


		inputAbility.doAbility(actionTaker,receiver, multiplier);


	} else if (action == "wait") {

		//Make something that increases energy here

		cout << actionTaker->getName() << " just waited\n";
	}

}

void setUpTypeMatchups(){

	//First make each match-up a 1
	for(int row = 0; row < NUM_OF_TYPES; row++){
		for(int col = 0; col < NUM_OF_TYPES; col++){

			typeMatchups[row][col] = 1.0;
		}
	}

	//Normal is not weak or strong against any type

	//Fire is strong against grass
	typeMatchups[FIRE][GRASS] = 2.0;

	//Fire is weak against water
	typeMatchups[FIRE][WATER] = 0.5;

	//Water is strong against fire
	typeMatchups[WATER][FIRE] = 2.0;

	//Water is weak against grass
	typeMatchups[WATER][GRASS] = 0.5;

	//Grass is strong against water
	typeMatchups[GRASS][WATER] = 2.0;

	//Grass is weak against fire
	typeMatchups[GRASS][FIRE] = 0.5;




}
