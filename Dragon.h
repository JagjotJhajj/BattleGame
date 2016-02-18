/*
 * Dragon.h
 *
 *  Created on: Feb 17, 2016
 *      Author: Jhajj
 */

#include <string>
#include <vector>
#include "Character.h"
using namespace std;

#ifndef DRAGON_H_
#define DRAGON_H_

class Dragon: public Character {
public:
	Dragon();
	virtual ~Dragon();

	Dragon(int level);
};

#endif /* DRAGON_H_ */
