/*
this is my first game
13/04/2026
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <typeinfo>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "character.h"
#include "weapon.h"
#include "inventory.h"
#include "player.h"
#include "warrior.h"
#include "enemy.h"
#include "data.h"
#include "level.h"
#include "dungeon.h"

#include "raylib.h"

float calculateDamage(Player *player, Enemy *enemy)
{
	int critRoll = rand() % 100 + 1;
	int damage = 0;
	if (critRoll > 80)
	{
		damage = player->getStrength() * 1.5f;
		std::cout << "Critical Hit!" << std::endl;
	}
	else if (critRoll > 30)
	{
		if (player->getStrength() > enemy->getDefense())
		{
			damage = player->getStrength() - enemy->getDefense();
		}
		else
		{
			damage = 1;
		}
	}
	else
	{
		damage = player->getStrength() * 0.5f;
		std::cout << "Grazed..." << std::endl;
	}

	if (enemy->weakTo == player->weapon.weapon)
	{
		std::cout << "Enemy is weak against your weapon!" << std::endl;
		damage = damage + player->weapon.bonusDamage * 2;
	}
	else
	{
		damage = damage + player->weapon.bonusDamage;
	}
	return damage;
}

enum GameState
{
	TITLE,
	MAIN_MENU,
	DUNGEON,
	BATTLE,
	INVENTORY,
	PAUSE,
	GAME_OVER
};

enum BattleState
{
	PLAYER_TURN,
	ENEMY_TURN,
	BATTLE_END
};

void showTitleScreen(int cursor)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawText("DUNGEON RPG", 100, 100, 24, WHITE);
	if (cursor == 0)
	{
		DrawText("->New Game", 100, 160, 20, LIGHTGRAY);
	}
	else
	{
		DrawText("New Game", 100, 160, 20, LIGHTGRAY);
	}
	if (cursor == 1)
	{
		DrawText("->Load Game", 100, 190, 20, LIGHTGRAY);
	}
	else
	{
		DrawText("Load Game", 100, 190, 20, LIGHTGRAY);
	}
	if (cursor == 2)
	{
		DrawText("->Quit Game", 100, 220, 20, LIGHTGRAY);
	}
	else
	{
		DrawText("Quit Game", 100, 220, 20, LIGHTGRAY);
	}
	EndDrawing();
}

void showMainMenu()
{
	std::cout << "=== CHOOSE AN OPTION ===" << std::endl
			  << std::endl;
	std::cout << "1. View Character" << std::endl;
	std::cout << "2. View Inventory" << std::endl;
	std::cout << "3. Equip Weapon" << std::endl;
	std::cout << "4. Enter Dungeon" << std::endl;
	std::cout << "5. Return to title" << std::endl;
}

void showDungeonMenu()
{
	std::cout << "=== CHOOSE AN OPTION ===" << std::endl
			  << std::endl;
	std::cout << "1. Fight" << std::endl;
	std::cout << "2. Inventory" << std::endl;
	std::cout << "3. Exit" << std::endl;
}

void showBattleMenu()
{
	std::cout << "CHOOSE ACTION:" << std::endl
			  << std::endl;
	std::cout << "1. Attack" << std::endl;
	std::cout << "2. Use Potion" << std::endl;
	std::cout << "3. Flee" << std::endl;
	std::cout << "4. Pause" << std::endl;
}

void showInventoryMenu()
{
	std::cout << "1. use potion" << std::endl;
	std::cout << "2. close" << std::endl;
}

int getMenuChoice()
{
	bool choice = false;
	int cursor = 0;
	while (!choice)
	{
		if (IsKeyPressed(KEY_W))
			cursor == 0 ? cursor = 2 : cursor -= 1;
		if (IsKeyPressed(KEY_S))
			cursor == 2 ? cursor = 0 : cursor += 1;
		if (IsKeyPressed(KEY_ENTER))
			choice = true;
		showTitleScreen(cursor);
	}
	return cursor;
}

int main()
{
	InitWindow(800, 600, "RPG");
	SetTargetFPS(60);

	srand(time(NULL));
	GameState state = TITLE;
	GameState previousState = TITLE;
	BattleState battleState = PLAYER_TURN;
	BattleState previousBattleState = PLAYER_TURN;

	bool gameRunning = true;

	Warrior *player = new Warrior();
	player->initializeClass(); // placeholder to distribute stats based on level

	std::vector<std::string> rooms;
	std::vector<std::string> enemies;
	std::vector<int> enemyHPs;

	int gold = 10;
	float critical = 1.2f;
	float damage;

	int round = 0;
	bool isStunned = false;

	Level level = Level();
	level.loadLevel("level1.txt", rooms, enemies, enemyHPs);

	Dungeon dungeon(player);

	// dungeon.displayMap();
	showTitleScreen(0);

	int enemyN = rand() % enemies.size();
	Enemy *enemy = new Enemy("Sword", 20);
	enemy->name = enemies[enemyN];
	enemy->setMaxHp(enemyHPs[enemyN]);
	enemy->setHp(enemyHPs[enemyN]);
	enemy->setStrength(enemy->level * 3.0f);
	enemy->setDefense(enemy->level * 1.0f);

	while (gameRunning && !WindowShouldClose())
	{
		switch (state)
		{
		case TITLE:
			// showTitleScreen();
			switch (getMenuChoice())
			{
			case 0:
				std::cout << "Starting a new game..." << std::endl;
				player->setName();
				state = MAIN_MENU;
				break;
			case 1:
				std::cout << "Loading game..." << std::endl;
				Data::loadGame(player);
				player->initializeClass(); // placeholder to distribute stats based on level
				state = MAIN_MENU;
				break;
			case 2:
				gameRunning = false;
				break;
			default:
				// std::cout << "Starting a new game..." << std::endl;
				// state = MAIN_MENU;
				break;
			}
			break;
		case MAIN_MENU:
			showMainMenu();
			switch (getMenuChoice())
			{
			case 1:
				player->viewCharacter();
				break;
			case 2:
				player->inventory.viewInventory();
				break;
			case 3:
				player->weapon.equipWeapon();
				break;
			case 4:
				state = DUNGEON;
				break;
			case 5:
				state = TITLE;
				break;
			}
			break;
		case DUNGEON:
		{
			dungeon.displayMap();

			// std::vector<Node *> path = dungeon.findPath(player->tileX, player->tileY, 3, 3);
			// // Test A* pathfinding
			// if (path.empty())
			// {
			// 	std::cout << "No path found!\n";
			// }
			// else
			// {
			// 	std::cout << "Path length: " << path.size() << "\n";
			// 	std::cout << "Path: ";
			// 	for (Node *n : path)
			// 	{
			// 		std::cout << "(" << n->x << "," << n->y << ") ";
			// 	}
			// 	std::cout << "\n";

			// 	// Clean up path nodes
			// 	for (Node *n : path)
			// 	{
			// 		delete n;
			// 	}
			// }

			// std::cout << "Position: (" << player->tileX << ", " << player->tileY << ")\n";
			// std::cout << "Move: ";

			// char cmd;

			// if (!(std::cin >> cmd))
			// {
			// 	std::cin.clear();
			// 	std::cin.ignore(10000, '\n');
			// 	break;
			// }
			// if (cmd == 'Q' || cmd == 'q')
			// {
			// 	state = MAIN_MENU;
			// 	break;
			// }

			// char cmd;
			// auto key = 0;
			// if (!GetKeyPressed()) {
			// 	std::cin >> cmd;
			// 	std::cout << cmd << std::endl;
			// 	key = GetKeyPressed();

			// 	std::cout << "key: " << key << std::endl;
			// } else{
			// 	std::cout << key << std::endl;
			// }

			if (!player->isMoving)
			{
				if (IsKeyPressed(KEY_W))
					dungeon.movePlayer('N');
				if (IsKeyPressed(KEY_A))
					dungeon.movePlayer('W');
				if (IsKeyPressed(KEY_S))
					dungeon.movePlayer('S');
				if (IsKeyPressed(KEY_D))
					dungeon.movePlayer('E');
				if (IsKeyPressed(KEY_Q))
					state = MAIN_MENU;
			}

			// dungeon.movePlayer();
			break;
		}
			// std::cout << std::endl
			// 		  << "You enter the dungeon" << std::endl;
			// showDungeonMenu();
			// switch (getMenuChoice())
			// {
			// case 1:
			// 	std::cout << "=== BATTLE ===" << std::endl;
			// 	std::cout << "You see " << enemies[enemyN] << std::endl
			// 			  << std::endl;
			// 	state = BATTLE;
			// 	battleState = PLAYER_TURN;
			// 	break;
			// case 2:
			// 	state = INVENTORY;
			// 	break;
			// case 3:
			// 	std::cout << "You exit the dungeon." << std::endl;
			// 	state = MAIN_MENU;
			// 	break;
			// }
		case BATTLE:
			switch (battleState)
			{
			case BATTLE_END:
				if (enemy->getHp() <= 0)
				{
					if (player->defeatedEnemies.count(enemy->name) == 0)
					{
						player->defeatedEnemies.insert(enemy->name);
					}
					player->xpNeeded = player->xpNeeded - enemy->xpReward;
					std::cout << "XP to next level: " << player->xpNeeded << std::endl;
					std::vector<std::string> loot = {"potion", "sword", "meat"};
					std::sort(loot.begin(), loot.end());
					auto it = std::find(loot.begin(), loot.end(), "potion");
					if (it != loot.end())
					{
						std::cout << "You found a potion!" << std::endl;
						player->inventory.addItem("potion");
					}
					player->inventory.viewInventory();
					for (const auto &enemyName : player->defeatedEnemies)
					{
						std::cout << "Defeated: ";
						std::cout << enemyName << std::endl;
					}
					Data::saveGame(player);
					state = DUNGEON;
					break;
				}
				else if (player->getHp() <= 0)
				{
					state = GAME_OVER;
					break;
				}

				break;

			case PLAYER_TURN:
				round++;
				std::cout << "Round " << round << " begins!" << std::endl;
				if (isStunned)
				{
					std::cout << "Stunned! Turn Skipped." << std::endl;
					isStunned = false;
					battleState = ENEMY_TURN;
					break;
				}
				player->checkHp();
				showBattleMenu();
				switch (getMenuChoice())
				{
				case 1:
					std::cout << std::endl
							  << "=== BATTLE ===" << std::endl;
					player->attack(*enemy);
					damage = calculateDamage(player, enemy);
					std::cout << player->weapon.weaponEffect << std::endl;
					std::cout << "Damage dealt: " << damage << std::endl;
					enemy->takeDamage(damage);
					if (enemy->getHp() <= 0)
					{
						battleState = BATTLE_END;
					}
					else
					{
						battleState = ENEMY_TURN;
					}
					break;
				case 2:
					if (player->inventory.getItem("potion"))
					{
						player->inventory.removeItem("potion");
						std::cout << "You have " << player->inventory.getItem("potion") << " left" << std::endl;
						player->healDamage(20);
					}
					else
					{
						std::cout << std::endl
								  << "You have no potions left" << std::endl;
						round--;
						break;
					}
					break;
				case 3:
					std::cout << player->name << " flees the battle!" << std::endl;
					state = DUNGEON;
					break;
				case 4:
					previousState = BATTLE;
					previousBattleState = battleState;
					state = PAUSE;
					break;
				}
				break;
			case ENEMY_TURN:
				if (enemy->getHp() > 0)
				{
					enemy->attack(*player);
					if (player->getHp() <= 0)
					{
						battleState = BATTLE_END;
						break;
					}
					else
					{

						battleState = PLAYER_TURN;
					}
				}
				break;
			default:
				break;
			}
			break;
		case GAME_OVER:
			std::cout << "GAME OVER" << std::endl;
			gameRunning = false;
			break;

		case PAUSE:
			std::cout << "\n=== PAUSED ===" << std::endl;
			std::cout << "1. Resume" << std::endl;
			std::cout << "2. Save Game" << std::endl;
			std::cout << "3. Quit to Title" << std::endl;

			switch (getMenuChoice())
			{
			case 1:
				state = previousState;
				battleState = previousBattleState;
				break;

			case 2:
				Data::saveGame(player);
				break;
			case 3:
				state = TITLE;
				break;
			}
			break;
		case INVENTORY:
			player->inventory.viewInventory();
			showInventoryMenu();
			switch (getMenuChoice())
			{
			case 1:
				if (player->inventory.getItem("potion"))
				{
					player->inventory.removeItem("potion");
					std::cout << "You have " << player->inventory.getItem("potion") << " left" << std::endl;
					player->healDamage(20);
				}
				else
				{
					std::cout << std::endl
							  << "You have no potions left" << std::endl;
					round--;
					break;
				}
				break;
			case 2:
				state = DUNGEON;
				break;
			}
			break;

		default:
			break;
		}
	}

	// std::cout << player->weaponDamage["Sword"] << std::endl;

	delete player;
	delete enemy;
	CloseWindow();
	return 0;
}
