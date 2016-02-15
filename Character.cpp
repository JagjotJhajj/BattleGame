/*
 * Character.cpp
 *
 *  Created on: Feb 14, 2016
 *      Author: Jhajj
 */


#include "Character.h"


Character::Character() {
	level = 1;
	attack = 0;
	defense = 0;
	health = 0;
	energy = 0;
}

Character::~Character() {

}

Character::Character(int lvl, int atk, int def, int hp, int eng, string name){

	level = lvl;
	attack = atk;
	defense = def;
	health = hp;
	energy = eng;
	isDead = false;
	this->name = name;

}

int Character::getLevel() const{
	return level;
}

int Character::getAttack() const{
	return attack;
}

int Character::getDefense() const{
	return defense;
}

int Character::getHealth() const{
	return health;
}

int Character::getEnergy() const{
	return energy;
}

bool Character::getIsDead() const{
	return isDead;
}

void Character::takeDamage(int damage){

	if(health<=damage){
		health = 0;
		isDead = true;
	}
	else{
		health -=damage;
	}
}

string Character::getAction(){
	return "attack";
}

string Character::getName() const{
	return name;
}


