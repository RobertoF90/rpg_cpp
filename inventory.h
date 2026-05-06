#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <map>

class Inventory
{
private:
	std::map<std::string, int> items;

public:
	Inventory()
	{
		items["potion"] = 2;
		items["torch"] = 1;
	};

	void viewInventory();

	void addItem(std::string item);

	bool getItem(std::string item);

	std::map<std::string, int> &getItems()
	{
		return items;
	}

	void removeItem(std::string item);
};

#endif
