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

void Menu::showMainMenu()
{
    getMenuChoice(5);

    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Main Menu", 100, 100, 24, WHITE);
    if (cursor == 0)
    {
        DrawText("->View Character", 100, 160, 20, LIGHTGRAY);
    }
    else
    {
        DrawText("View Character", 100, 160, 20, LIGHTGRAY);
    }
    if (cursor == 1)
    {
        DrawText("->View Inventory", 100, 190, 20, LIGHTGRAY);
    }
    else
    {
        DrawText("View Inventory", 100, 190, 20, LIGHTGRAY);
    }
    if (cursor == 2)
    {
        DrawText("->Equip Weapon", 100, 220, 20, LIGHTGRAY);
    }
    else
    {
        DrawText("Equip Weapon", 100, 220, 20, LIGHTGRAY);
    }
    if (cursor == 3)
    {
        DrawText("->Enter Dungeon", 100, 250, 20, LIGHTGRAY);
    }
    else
    {
        DrawText("Enter Dungeon", 100, 250, 20, LIGHTGRAY);
    }
    if (cursor == 4)
    {
        DrawText("->Return to title", 100, 280, 20, LIGHTGRAY);
    }
    else
    {
        DrawText("Return to title", 100, 280, 20, LIGHTGRAY);
    }

    EndDrawing();
}

void Menu::resetMenu()
{
    std::cout << "resetting menu" << std::endl;
    choice = 0;
    cursor = 0;
}