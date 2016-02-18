/*
 * This is the character the user uses
 */
#include "Protagonist.h"

/*
 * Default constructor
 */
Protagonist::Protagonist() {

}
/*
 * Default destructor
 */
Protagonist::~Protagonist() {
}

/*
 * The constructor, caller only has control over the name of the character
 */
Protagonist::Protagonist(string name) {
	level = 10;
	attack = 30;
	defense = 30;
	health = 200;
	energy = 200;
	isDead = false;
	this->name = name;
	characterType = NORMAL;

	Ability Punch(0, 10, "punch", NORMAL);
	Ability Waterbomb(30, 50, "waterbomb", WATER);
	Ability Treehammer(40, 60, "treehammer", GRASS);
	Ability Inferno(50, 70, "inferno", FIRE);
	Ability Sunder(80, 100, "sunder", NORMAL);

	abilities.push_back(Punch);
	abilities.push_back(Waterbomb);
	abilities.push_back(Treehammer);
	abilities.push_back(Inferno);
	abilities.push_back(Sunder);
}

/*
 * Does an action against a target, allows the user to choose which ability is used
 */
void Protagonist::doAction(Character *target) {
	string inputAbilityName;
	set<string> abilityNames = getAbilityNames();

	do {
		cout << "Choose an attack (current energy is " << getEnergy() << ")\n";
		printAbilities();
		cin >> inputAbilityName;
	} while (!isStringInSetIgnoreCase(inputAbilityName, abilityNames));

	Ability inputAbility = getAbilityFromName(inputAbilityName);

	cout << getName() << " used " << inputAbilityName << "\n";

	double multiplier = getMultiplier(inputAbility.getType(),
			target->getType());

	inputAbility.doAbility(this, target, multiplier);

}
