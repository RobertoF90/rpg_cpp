#ifndef MENU_H
#define MENU_H

// #include "player.h"

class Menu
{

public:
    //  Menu(

    //         std::string weakTo = "Sword",
    //         int xpReward = 5)
    //         : Character()
    //     {
    //         this->weakTo = weakTo;
    //         this->xpReward = xpReward;
    //     };

    int choice = 0;
    int cursor = 0;

    void getMenuChoice(int options);

    void showTitleScreen();
    void showMainMenu();

    void resetMenu();
};

#endif
