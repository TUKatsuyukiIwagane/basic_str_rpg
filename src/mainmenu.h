#ifndef MAINMENU_H
#define MAINMENU_H

enum{
    MAINMENU_STORY, // story start
    MAINMENU_BATTLE, // battle start
    MAINMENU_ITEM, // item
    MAINMENU_MAX // main menu max
};
extern char mainMenu[MAINMENU_MAX][4 * 3 + 1];
void Mainmenu();
void selectMainmenuCommand();
#endif