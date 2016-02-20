/*
 * A Dragon is a type of enemy character.
 */
#include "Dragon.h"



Dragon::Dragon() {
	// TODO Auto-generated constructor stub

}

Dragon::~Dragon() {
	// TODO Auto-generated destructor stub
}

Dragon::Dragon(int level){

	this->level = level;
	this->attack = level * 3;
	this->defense = level;
	this->health = level * 10;
	this->energy = INT_MAX;
	this->isDead = false;
	this->name = "Dragon";
	this->characterType = FIRE;

	Ability Claw(5, 10, "claw", NORMAL);
	Ability Firebreath(50, 50, "firebreath", FIRE);

	abilities.push_back(Claw);
	abilities.push_back(Firebreath);



}
