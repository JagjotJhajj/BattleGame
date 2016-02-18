/*
 * Protagonist.h
 *
 *  Created on: Feb 17, 2016
 *      Author: Jhajj
 */

#include "Character.h"
#include "Main.h"
#ifndef PROTAGONIST_H_
#define PROTAGONIST_H_

class Protagonist: public Character {
public:
	Protagonist();
	virtual ~Protagonist();

	Protagonist(string name);

	void doAction(Character *target);

};

#endif /* PROTAGONIST_H_ */
