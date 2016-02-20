/*
 * A fish is a type of enemy character
 */
#include "Fish.h"
Fish::Fish() {

}

Fish::~Fish() {
}

Fish::Fish(int level){

	this->level = level;
	attack = (level/2) + 3;
	defense = (level/3) + 1;
	health = level * 4;
	energy = INT_MAX;
	isDead = false;
	name = "Fish";
	characterType = WATER;

	Ability Slap(0, 2, "slap", NORMAL);
	Ability Splash(5, 10, "splash", WATER);
	Ability SeaweedStrike(7, 13, "seaweed strike", GRASS);

	abilities.push_back(Slap);
	abilities.push_back(Splash);
	abilities.push_back(SeaweedStrike);


}
