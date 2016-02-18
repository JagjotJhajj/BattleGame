/*
 * Fish.h
 *
 *  Created on: Feb 17, 2016
 *      Author: Jhajj
 */

#ifndef FISH_H_
#define FISH_H_
#include "Character.h"
class Fish : public Character {
public:
	Fish();
	virtual ~Fish();

	Fish(int level);

private:
	int level;
};

#endif /* FISH_H_ */
