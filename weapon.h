#ifndef WEAPON_H
#define WEAPON_H

#include <vector>
#include <string>

class Weapon
{
public:
	Weapon(
		std::vector<std::string> weapons = {
			"Sword",
			"Staff",
			"Bow",
		},
		std::string weapon = "Sword", float bonusDamage = 0, std::string weaponEffect = "")
	{
		this->weapons = weapons;
		this->weapon = weapon;
		this->bonusDamage = bonusDamage;
		this->weaponEffect = weaponEffect;
	};

	std::vector<std::string> weapons;
	std::string weapon;
	float bonusDamage;
	std::string weaponEffect;

	void equipWeapon();
};

#endif
