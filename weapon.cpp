#include <iostream>
#include <vector>
#include "weapon.h"
#include "player.h"
#include "inventory.h"

void Weapon::equipWeapon()
{
	int choice;
	std::cout << "1 - " << weapons[0] << std::endl;
	std::cout << "2 - " << weapons[1] << std::endl;
	std::cout << "3 - " << weapons[2] << std::endl
			  << std::endl;
	std::cout << "Select your weapon: (number)" << std::endl;
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		bonusDamage = 3;
		weaponEffect = "*slashhh*";
		break;
	case 2:
		bonusDamage = 1.5;
		weaponEffect = "*bonkk*";
		break;
	case 3:
		bonusDamage = 2;
		weaponEffect = "*sproinggg*";
		break;
	default:
		bonusDamage = 0.5;
		weaponEffect = "*smackkk*";
		std::cout << "You did not select a weapon." << std::endl
				  << std::endl;
		break;
	}
	std::cout << "You equipped: " << weapons[choice - 1] << std::endl;

	weapon = weapons[choice - 1];

	std::cout << "Your weapon has +" << bonusDamage << " attack." << std::endl;
}
