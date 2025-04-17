#include "character.h"
#include <stdio.h>

Character characters[CHARACTER_MAX];

Character monsters[MONSTER_MAX] = {
    //player
    {
        15, // HP
        15, // maxHP
        15, // MP
        15, // maxMP
        3, // attack
        "勇者", // name
    },

    //slime
    {
        3, // HP
        3, // maxHP
        0, // MP
        0, // maxMP
        2, // attack
        "スライム", // name
        "／・Д・＼¥n"  // AA
    },
};


void Init(){
    characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
   } 
