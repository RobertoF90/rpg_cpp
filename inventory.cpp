#include <iostream>
#include <string>
#include <vector>
#include "inventory.h"

void Inventory::viewInventory()
{
	std::cout << std::endl
			  << " === INVENTORY === " << std::endl;
	for (const auto &pair : items)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	std::cout << std::endl;
}

void Inventory::addItem(std::string item)
{
	items[item]++;
}

bool Inventory::getItem(std::string item)
{
	for (const auto &pair : items)
	{
		if (pair.first == item)
		{
			return true;
		}
	}
	return false;
}
void Inventory::removeItem(std::string item)
{
	for (auto it = items.begin(); it != items.end(); ++it)
	{
		if (it->first == item)
		{
			it->second--;
			std::cout << "You used a " << item << std::endl;
			if (it->second <= 0)
			{
				items.erase(it);
			}
			return;
		}
	}
}
