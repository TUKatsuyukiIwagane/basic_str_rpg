#include "effect_command.h"
#include "battle.h"
#include "character.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void physic_attack(int attacker){
    printf("%s の攻撃！", characters[attacker].name);
    //calc damage
    int damage = 1 + rand() % characters[attacker].attack;
    //adapt damage
    characters[characters[attacker].target].hitpoints -= damage;
    if (characters[characters[attacker].target].hitpoints < 0){
        characters[characters[attacker].target].hitpoints = 0;
        } // does not go below 0
        DrawBattleScreen();
        printf("%s に %d のダメージを与えた！\n", characters[characters[attacker].target].name, damage);
}