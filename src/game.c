#include <stdio.h>
#include "battle.h"
#include "character.h"
#include "effect_command.h"
#include "player.h"
#include "levelup.h"
#include "mainmenu.h"
#include <time.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    InitPlayer();
    //initialize player
    Init();
    Mainmenu();
    DrawBattleScreen();
    return 0;
}