/*
 * The Ability class
 *
 * Abilities are what characters "Attack" with, although some can affect stats as well
 */
#include "Ability.h"
#include "Character.h"
#include <stdlib.h>

/*
 * Destructor
 */
Ability::~Ability() {
}

/*
 * Constructor
 */
Ability::Ability(int cost, int power, string name){
	this->cost = cost;
	this->power = power;
	this->name = name;
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

/*
 * Executes an ability, the user is the one using the ability on the receiver
 *
 * Precondition: User has enough energy to do the abillity
 *
 */
void Ability::doAbility(Character *user, Character *receiver){

	if(user->getEnergy() < cost){
		cout << "User did not have enough energy!";

	}
	else{

	user->loseEnergy(cost);
	int damage = power + user->getAttack() - receiver->getDefense();
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

