#include "battle.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>

char commandNames[COMMAND_MAX][4 * 3 + 1]={
    "戦う", // COMMAND_FIGHT
    "呪文", // COMMAND_SPELL
    "逃げる", // COMMAND_RUN
   };

void Battle(int _monster){
    characters[CHARACTER_MONSTER] = monsters[_monster];
    printf("%s があらわれた！\n", characters[CHARACTER_MONSTER].name);
    //wait entering keyboard
    getchar();
    while(1){
        SelectCommand(); //for selecting command
        //roop during battle
        for (int i = 0; i < CHARACTER_MAX; i++){
            DrawBattleScreen();
            switch (characters[i].command){
            case COMMAND_FIGHT: //fight
            printf("%s の攻撃！", characters[i].name);
            getchar();
                break;
            case COMMAND_SPELL: //spell magic
                break;
            case COMMAND_RUN: //run away
                break;
            
            default:
                break;
            }
        }
    }
}

void SelectCommand(){
    while (1){
        DrawBattleScreen();
        for (int i = 0; i < COMMAND_MAX; i++){
            if (i == characters[CHARACTER_PLAYER].command){
            printf("＞"); // 選択中のコマンドなら，カーソルを描画
            }else{
            printf(" "); // 選択されていないコマンドの前に全角スペースを描画
            }
            printf("%s\n", commandNames[i]);
        }
        for (int i = 0; i < COMMAND_MAX; i++){
            characters[CHARACTER_PLAYER].command = (COMMAND_MAX + characters[CHARACTER_PLAYER].command) % COMMAND_MAX;
            printf("%s\n", commandNames[i]);
            }
            switch (getchar()){
                //branch out by key entered
            case 'w': // if enter w key
                characters[CHARACTER_PLAYER].command--;
                break;
            case 's': // if enter s key
                characters[CHARACTER_PLAYER].command++;
                break;
            case '\n':
                return;
            default:
                break;
            }
                while(getchar() != '\n'){
                    ; //ignore multiple enter
                }
    }
    
}

void DrawBattleScreen(){
    system("clear");
    printf("%s/n", characters[CHARACTER_PLAYER].name);
    printf("HP: %d/%d MP: %d/%d/n",
    characters[CHARACTER_PLAYER].hitpoints,
    characters[CHARACTER_PLAYER].maxHp,
    characters[CHARACTER_PLAYER].magicpoints,
    characters[CHARACTER_PLAYER].maxMp );
    printf("\n"); // 次の表示のために 1 行空ける
     // モンスターのアスキーアートを描画する
    printf("%s", characters[CHARACTER_MONSTER].aa);
    printf(" (HP: %d/%d)\n",
    characters[CHARACTER_MONSTER].hitpoints,
    characters[CHARACTER_MONSTER].maxHp);
    printf("\n"); // 次の表示に備えて 1 行空ける
}