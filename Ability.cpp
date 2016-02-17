/*
 * The Ability class
 *
 * Abilities are what characters "Attack" with, although some can affect stats as well
 */
#include "Ability.h"
#include "Character.h"
#include <stdlib.h>
/*
 * Constructor
 */
Ability::Ability(){

}
/*
 * Destructor
 */
Ability::~Ability() {
}

/*
 * Constructor
 */
Ability::Ability(int cost, int power, string name, int abilityType){
	this->cost = cost;
	this->power = power;
	this->name = name;
	this->abilityType = abilityType;
}

/*
 * Observer methods
 */
int Ability::getPower() const{
	return power;
}

string Ability::getName() const{
	return name;
}

int Ability::getCost() const{
	return cost;
}

int Ability::getType() const{
	return abilityType;
}

/*
 * Executes an ability, the user is the one using the ability on the receiver
 *
 *
 */
void Ability::doAbility(Character *user, Character *receiver, double multiplier){

	if(user->getEnergy() < cost){
		cout << "Not enough energy! The attack failed\n";

	}
	else{


		if(multiplier > 1.1){
			cout << "It's super effective!\n";
		}
		else if(multiplier < 0.9){
			cout << "It's not very effective!\n";
		}


	user->loseEnergy(cost);
	int damage =(int)(multiplier *(power + user->getAttack() - receiver->getDefense()));
	if(damage < 1){
		damage = 1;
	}

	receiver->takeDamage(damage);


	cout << receiver->getName() << " just took " << damage << " damage and has "
			<< receiver->getHealth() << " health left.\n";
	}
}

/*
 * TODO: This function will make the ability able to change stats
 */
void Ability::setStatusChange(string stat, bool affectUser, int change, int multiplier){

}

