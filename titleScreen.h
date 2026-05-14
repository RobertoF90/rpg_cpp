#ifndef TITLESCREEN_H
#define TITLESCREEN_H

// #include "player.h"

class TitleScreen
{

public:
    bool choice = false;
    int cursor = 0;

    int getMenuChoice(int options);

    void showTitleScreen();
    // void showMainMenu();
};

#endif
