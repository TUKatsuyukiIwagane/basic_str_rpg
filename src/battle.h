#ifndef BATTLE_H
#define BATTLE_H

enum{
    COMMAND_FIGHT, // 闘う
    COMMAND_SPELL, // 呪文
    COMMAND_RUN, // 逃げる
    COMMAND_MAX // コマンド種類数
}; 


void Battleloop();
void Battle(int _monster);
void enableRawMode();
void disableRawMode();
void SelectCommand();
void DrawBattleScreen();

#endif