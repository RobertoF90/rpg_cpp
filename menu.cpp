#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "menu.h"

#include <fstream>
#include <sstream>

#include <algorithm>
#include <cctype>

#include "raylib.h"

void Menu::getMenuChoice(int options)
{

    if (choice)
    {
        resetMenu();
    }

    if (!choice)
    {
        if (IsKeyPressed(KEY_W))
            cursor == 0 ? cursor = options - 1 : cursor -= 1;
        if (IsKeyPressed(KEY_S))
            cursor == options - 1 ? cursor = 0 : cursor += 1;
        if (IsKeyPressed(KEY_ENTER))
            choice = cursor + 1;
    }
}

void Menu::showTitleScreen()
{
    getMenuChoice(3);

    int x = GetScreenWidth() / 4;
    int y = GetScreenHeight() / 2 + GetScreenHeight() / 4;
    int w = 120;
    int h = 24;

    ClearBackground(BLACK);
    BeginDrawing();
    DrawText("DUNGEON RPG", x - w, y - GetScreenHeight() / 2, 48, WHITE);

    DrawText("New Game", x - w, y, 20, LIGHTGRAY);
    DrawText("Load Game", x - w, y + 32, 20, LIGHTGRAY);
    DrawText("Quit Game", x - w, y + 64, 20, LIGHTGRAY);

    DrawRectangleLines(x - w - 8, y - 2 + (32 * cursor), w, h, ORANGE);

    EndDrawing();
}

void Menu::showMainMenu()
{
    getMenuChoice(5);

    int x = GetScreenWidth() / 2;
    int y = GetScreenHeight() / 4;
    int w = 196;
    int h = 24;

    ClearBackground(BLACK);
    BeginDrawing();

    DrawText("Main Menu", x - w, y - 64, h, WHITE);
    DrawText("View Character", x - w, y, 20, LIGHTGRAY);
    DrawText("View Inventory", x - w, y + 32, 20, LIGHTGRAY);
    DrawText("Equip Weapon", x - w, y + 64, 20, LIGHTGRAY);
    DrawText("Enter Dungeon", x - w, y + 96, 20, LIGHTGRAY);
    DrawText("Return to title", x - w, y + 128, 20, LIGHTGRAY);

    DrawRectangleLines(x - w - 8, y - 2 + (32 * cursor), w, h, ORANGE);

    EndDrawing();
}

void Menu::resetMenu()
{
    choice = 0;
    cursor = 0;
}