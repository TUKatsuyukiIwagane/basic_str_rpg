#include "story_func.h"
#include "flags.h"
#include "subfunc.h"
#include "battle.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char choiceYesorNo[CHOICE_MAX][4 * 3 + 1]={
    "はい", // say yes
    "いいえ" // say no
};

void storyProcess() {
    // Example of how to use the flags
    while(1){
        if (storyFlags.started == 0) {
            descriptionStory("story_descript.txt", "[start]");
            storyFlags.started = 1;
        }
        if (storyFlags.kingAppeared == 0) {
            descriptionStory("story_descript.txt", "[king_first_appearance]");
            selectYesorNo();
            switch (characters[CHARACTER_PLAYER].command) {
                case CHOICE_ONE:
                    descriptionStory("story_descript.txt", "[king_suggest]");
                    storyFlags.kingAppeared = 1;
                    break;
                case CHOICE_TWO:
                    descriptionStory("story_descript.txt", "[king_refuse]");
                    //最悪。後で関数化マスト。
                    characters[CHARACTER_PLAYER].hitpoints = 0;
                    printf("ゲームオーバー！\n");
                    printf("メニューに戻ります。\n");
                    getchar();
                    system("clear");
                    characters[CHARACTER_PLAYER].hitpoints = characters[CHARACTER_PLAYER].maxHp;
                    characters[CHARACTER_PLAYER].magicpoints = characters[CHARACTER_PLAYER].maxMp;
                    Mainmenu();
                    break;
            }
            descriptionStory("story_descript.txt", "[go_battle_slime]");
            Battle(MONSTER_SLIME);
        }

    // if (storyFlags.getWeapon == 0) {
    //     printf("武器を手にいれた！\n");
    //     storyFlags.getWeapon = 1;
    // }
    // else if (storyFlags.defeatedEnemy == 0) {
    //     printf("スライムをたおした！\n");
    //     storyFlags.defeatedEnemy = 1;
    // }
    // else if (storyFlags.getAlly == 0) {
    //     printf("仲間をえた！\n");
    //     storyFlags.getAlly = 1;
    // }
    // else if (storyFlags.researchCastle == 0) {
    //     printf("敵の本拠地についた！\n");
    //     storyFlags.researchCastle = 1;
    // }
    // else if (storyFlags.defeatedBoss == 0) {
    //     printf("ボスをたおした！!\n");
    //     storyFlags.defeatedBoss = 1;
    // }
}
}
void descriptionStory(const char *filename, const char *storytags) {
    system("clear");
    printFile(filename, storytags);
    getchar(); // wait for enter key
}

void selectYesorNo() {
    enableRawMode();
    while (1) {
        characters[CHARACTER_PLAYER].command = (CHOICE_MAX + characters[CHARACTER_PLAYER].command) % CHOICE_MAX;
        system("clear");
        for (int i = 0; i < CHOICE_MAX; i++) {
            if (i == characters[CHARACTER_PLAYER].command) {
                printf("＞"); // 選択中のコマンドなら，カーソルを描画
            } else {
                printf(" "); // 選択されていないコマンドの前に全角スペースを描画
            }
            printf("%s\n", choiceYesorNo[i]);
        }
        switch (getchar()) {
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