/*
 * Main.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: Jhajj
 */

#include <iostream>
#include <string>

using namespace std;

#include "Character.h"

bool isValidAction(string action);
void doAction(string action, Character *actionTaker, Character *receiver);


int main() {

	Character Protagonist(5, 10, 2, 100, 100, "Your character");
	Character Enemy(2, 3, 1, 20, 5, "McEvil");

	cout << "Welcome to the game!\n";

	while (!Protagonist.getIsDead() && !Enemy.getIsDead()) {

		string action;

		do{
		cout << "Please choose to attack or wait\n";


		cin >> action;
		}while(!isValidAction(action));

		cout << Enemy.getHealth() << "\n";
		doAction(action, &Protagonist, &Enemy);
		cout << Enemy.getHealth() << "\n";

		if(Protagonist.getIsDead() || Enemy.getIsDead()){
			break;
		}

		doAction(Enemy.getAction(), &Enemy, &Protagonist);
		cout << "\n";
	}

	if(Protagonist.getIsDead()){
		cout << Protagonist.getName() << " died! " << Protagonist.getName() << " lost!\n";
	}

	else{
		cout << Enemy.getName() << " died! "<< Protagonist.getName() << " won!\n";

	}

	return 0;
}

bool isValidAction(string action){

	if(action == "attack" || action == "wait"){
		return true;
	}

	return false;

}

void doAction(string action, Character *actionTaker, Character *receiver){

if(action == "attack"){
	int damage = actionTaker->getAttack() - receiver->getDefense();
	if(damage < 1){
		damage = 1;
	}

	receiver->takeDamage(damage);

	cout <<receiver->getName() << " just took " << damage << " damage and has "
			<< receiver->getHealth() << " health left.\n";
}

else if(action == "wait"){
	//Make something that increases energy here

	cout << actionTaker->getName() << " just waited\n";
}

}

