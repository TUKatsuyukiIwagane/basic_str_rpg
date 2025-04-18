#include "mainmenu.h"
#include "character.h"
#include "battle.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char mainMenu[MAINMENU_MAX][4 * 3 + 1]={
    "物語", // story start
    "戦闘", // battle start
    "所持", // item
};

void Mainmenu(){
    characters[CHARACTER_PLAYER].command = 0;
    while (1){
        selectMainmenuCommand();
        switch (characters[CHARACTER_PLAYER].command){
            case MAINMENU_STORY:
                printf("物語\n");
                
                getchar();
                break;
            case MAINMENU_BATTLE:
                printf("戦闘\n");
                Battleloop();
                getchar();
                break;
            case MAINMENU_ITEM:
                printf("所持\n");
                getchar();
                break;
            default:
                break;
        }
    }
}

void selectMainmenuCommand(){
    enableRawMode();
    while (1){
        characters[CHARACTER_PLAYER].command = (MAINMENU_MAX + characters[CHARACTER_PLAYER].command) % MAINMENU_MAX;
        DrawBattleScreen();
        for (int i = 0; i < MAINMENU_MAX; i++){
            if (i == characters[CHARACTER_PLAYER].command){
            printf("＞"); // 選択中のコマンドなら，カーソルを描画
            }else{
            printf(" "); // 選択されていないコマンドの前に全角スペースを描画
            }
            printf("%s\n", mainMenu[i]);
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
                disableRawMode();
                return;
            default:
                break;
            }

            usleep(100000);
    }
    
}