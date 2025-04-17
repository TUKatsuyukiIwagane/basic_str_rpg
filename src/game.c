#include <stdio.h>
#include "battle.h"
#include "character.h"
#include "effect_command.h"
#include <time.h>
#include <stdlib.h>

void MainLoop(){
    while (characters[CHARACTER_PLAYER].hitpoints > 0){
        int nextMonster = MONSTER_START_INDEX + rand() % MONSTER_COUNT;
        Battle(nextMonster);
    }

    printf("ゲームオーバー！\n");
}

int main(){
    srand(time(NULL));
    InitPlayer();
    //initialize player

    Init();
    MainLoop();
    DrawBattleScreen();
    return 0;
}