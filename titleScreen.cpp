#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "titleScreen.h"

#include <fstream>
#include <sstream>

#include <algorithm>
#include <cctype>

#include "raylib.h"

int TitleScreen::getMenuChoice(int options)
{

    while (!choice)
    {
        if (IsKeyPressed(KEY_W))
            cursor == 0 ? cursor = options - 1 : cursor -= 1;
        // std::cout << "pressed W" << std::endl;
        if (IsKeyPressed(KEY_S))
            cursor == options - 1 ? cursor = 0 : cursor += 1;
        // std::cout << "pressed S" << std::endl;
        if (IsKeyPressed(KEY_ENTER))
            choice = true;
        // std::cout << "Enter" << std::endl;
    }
    return cursor;
}

void TitleScreen::showTitleScreen()
{
    if (IsKeyPressed(KEY_W))
        cursor == 0 ? cursor = 3 - 1 : cursor -= 1;
    // std::cout << "pressed W" << std::endl;
    if (IsKeyPressed(KEY_S))
        cursor == 3 - 1 ? cursor = 0 : cursor += 1;
    // std::cout << "pressed S" << std::endl;
    if (IsKeyPressed(KEY_ENTER))
        choice = cursor + 1;

    // std::cout << "Enter" << std::endl;

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
