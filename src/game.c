#include <stdio.h>
#include "battle.h"
#include "character.h"

int main(){
    Init();
    Battle(MONSTER_SLIME);
    DrawBattleScreen();
    return 0;
}