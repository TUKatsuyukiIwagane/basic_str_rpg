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
        0, // AA
        0, // command
        0, // target
        0, // experience
        1, // level
        1 // in player controlled
    },

    //slime
    {
        3, // HP
        3, // maxHP
        0, // MP
        0, // maxMP
        2, // attack
        "スライム", // name
        "／・Д・＼\n",  // AA
        0, // command
        0, // target
        3, // experience
        0, // level
        3, // gold
        0 // not in player controlled
    },

    //madhand
    {
        8, // HP
        8, // maxHP
        4, // MP
        4, // maxMP
        5, // attack
        "マドハンド", // name
        "艸　艸\n",  // AA
        0, // command
        0, // target
        5, // experience
        1, // level
        12, // gold
        0 // not in player controlled
    },

    //marderoctpass
    {
        10, // HP
        10, // maxHP
        5, // MP
        5, // maxMP
        6, // attack
        "殺人蛸", // name
        "≡(・◎・)≡\n",  // AA
        0, // command
        0, // target
        7, // experience
        1, // level
        15, // gold
        0 // not in player controlled
    },

    //cursedarmor
    {
        15, // HP
        15, // maxHP
        6, // MP
        6, // maxMP
        4, // attack
        "呪われた鎧", // name
        "|█＼[◎]／█|\n",  // AA
        0, // command
        0, // target
        8, // experience
        1, // level
        20, // gold
        0 // not in player controlled
    }
};


void Init(){
    characters[CHARACTER_PLAYER] = monsters[MONSTER_PLAYER];
   } 