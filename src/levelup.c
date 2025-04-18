#include "levelup.h"
#include "character.h"
#include"subfunc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int experienceTable[MAX_LEVEL] = {
    0, // level 0
    10, // level 1
    30, // level 2
    60, // level 3
    100, // level 4
    150, // level 5
    210, // level 6
    280, // level 7
    360, // level 8
    450, // level 9
};


void LevelUp(int character){
    if (characters[character].experience >= experienceTable[characters[character].level]){
        characters[character].level++;
        characters[character].hitpoints += power(3, characters[character].level);
        characters[character].maxHp += power(3, characters[character].level);
        characters[character].magicpoints += 1 + power(2, characters[character].level);
        characters[character].maxMp += 1 + power(2, characters[character].level);
        characters[character].attack += 2 * characters[character].level;
        printf("%s はレベルアップした！\n", characters[character].name);
        printf("Lv: %d -> %d\n", characters[character].level - 1, characters[character].level);
        printf("HP: %d -> %d\n", characters[character].hitpoints - power(3, characters[character].level), characters[character].hitpoints);
        printf("MP: %d -> %d\n", characters[character].magicpoints - (1 + power(2, characters[character].level)), characters[character].magicpoints);
        printf("攻撃力: %d -> %d\n", characters[character].attack - 1, characters[character].attack);
    }
}