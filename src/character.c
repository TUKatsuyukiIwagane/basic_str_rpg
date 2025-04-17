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
        "／・Д・＼¥n",  // AA
        0, // command
        0, // target
        3, // experience
        1, // level
        3, // gold
    },

    //madhand
    {
        8, // HP
        8, // maxHP
        4, // MP
        4, // maxMP
        5, // attack
        "マドハンド", // name
        "艸　艸¥n",  // AA
        0, // command
        0, // target
        5, // experience
        3, // level
        12, // gold
    },
};


void Init(){
    characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
   } 
