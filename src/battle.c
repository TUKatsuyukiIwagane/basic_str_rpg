#include "battle.h"
#include "character.h"
#include <stdio.h>

void Battle(int _monster){
    characters[CHARACTER_MONSTER] = monsters[_monster];
    //wait entering keyboard
    getchar();
}

void DrawBattleScreen(){
    printf("%s/n", characters[CHARACTER_PLAYER].name);
    printf("HP: %d/%d MP: %d/%d/n",
    characters[CHARACTER_PLAYER].hitpoints,
    characters[CHARACTER_PLAYER].maxHp,
    characters[CHARACTER_PLAYER].magicpoints,
    characters[CHARACTER_PLAYER].maxMp );
    printf("/n"); // 次の表示のために 1 行空ける
     // モンスターのアスキーアートを描画する
    printf("%s", characters[CHARACTER_MONSTER].aa);
    printf(" (HP: %d/%d)¥n",
    characters[CHARACTER_MONSTER].hitpoints,
    characters[CHARACTER_MONSTER].maxHp);
    printf("¥n"); // 次の表示に備えて 1 行空ける
}