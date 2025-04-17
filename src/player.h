#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int gold;  // 所持金
    char item[10][20];  // アイテム
    int itemCount[10];  // アイテムの個数
} Player;

extern Player player;
void InitPlayer();

#endif