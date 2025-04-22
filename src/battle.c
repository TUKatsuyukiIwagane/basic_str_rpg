#include "battle.h"
#include "character.h"
#include "effect_command.h"
#include "player.h"
#include "levelup.h"
#include "mainmenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>

char commandNames[COMMAND_MAX][4 * 3 + 1]={
    "戦う", // COMMAND_FIGHT
    "呪文", // COMMAND_SPELL
    "逃げる", // COMMAND_RUN
   };

void Battleloop(){
    while (characters[CHARACTER_PLAYER].hitpoints > 0){
        int nextMonster = MONSTER_START_INDEX + rand() % MONSTER_COUNT;
        Battle(nextMonster);
    }

    printf("ゲームオーバー！\n");
    printf("メニューに戻ります。\n");
    getchar();
    system("clear");
    characters[CHARACTER_PLAYER].hitpoints = characters[CHARACTER_PLAYER].maxHp;
    characters[CHARACTER_PLAYER].magicpoints = characters[CHARACTER_PLAYER].maxMp;
    Mainmenu();
}

void enableRawMode(){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

void disableRawMode(){
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    fcntl(STDIN_FILENO, F_SETFL, 0);
}

void Battle(int _monster){
    characters[CHARACTER_MONSTER] = monsters[_monster];
    printf("Lv %d %s があらわれた！\n", characters[CHARACTER_MONSTER].level ,characters[CHARACTER_MONSTER].name);
    //wait entering keyboard
    getchar();
    characters[CHARACTER_PLAYER].target = CHARACTER_MONSTER;
    characters[CHARACTER_MONSTER].target = CHARACTER_PLAYER;
    while(1){
        SelectCommand(); //for selecting command
        //roop during battle
        for (int i = 0; i < CHARACTER_MAX; i++){
            DrawBattleScreen();

            switch (characters[i].command){
            case COMMAND_FIGHT: //fight
                physicAttack(i);
                getchar();
                break;
            case COMMAND_SPELL: //spell magic
                spellAttack(i);
                getchar();
                break;
            case COMMAND_RUN: //run away
                if (runAway() == 0){
                    return;
                }
                getchar(); // wating enter key
                break;
            
            default:
                break;
            }
            if (characters[characters[i].target].hitpoints <= 0){
                switch (characters[i].target)
                {
                case CHARACTER_PLAYER:
                    printf("%s は死んでしまった！\n", characters[CHARACTER_PLAYER].name);
                    break;
                case CHARACTER_MONSTER:
                    strcpy(characters[characters[i].target].aa, "\n");
                    DrawBattleScreen(); 
                    printf("Lv %d %s を倒した！\n", characters[CHARACTER_MONSTER].level, characters[characters[i].target].name);
                    int rewardgold = 1 + rand() % characters[characters[i].target].gold;
                    characters[CHARACTER_PLAYER].gold += rewardgold;
                    int rewardexp = 1 + rand() % characters[characters[i].target].experience;
                    characters[CHARACTER_PLAYER].experience += rewardexp;
                    printf("経験値 %d を手に入れた！\n", characters[characters[i].target].experience);
                    printf("%d ゴールドを手に入れた！\n", rewardgold);
                    LevelUp(CHARACTER_PLAYER);
                    break;
                }
                getchar(); // wating enter key

                return;
               }
        }
    }
}

void SelectCommand(){
    enableRawMode();
    while (1){
        characters[CHARACTER_PLAYER].command = (COMMAND_MAX + characters[CHARACTER_PLAYER].command) % COMMAND_MAX;
        DrawBattleScreen();
        for (int i = 0; i < COMMAND_MAX; i++){
            if (i == characters[CHARACTER_PLAYER].command){
            printf("＞"); // 選択中のコマンドなら，カーソルを描画
            }else{
            printf(" "); // 選択されていないコマンドの前に全角スペースを描画
            }
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
                disableRawMode();
                return;
            default:
                break;
            }

            usleep(100000);
    }
    
}

void DrawBattleScreen(){
    system("clear");
    printf("%s\n", characters[CHARACTER_PLAYER].name);
    printf("HP: %d/%d MP: %d/%d\n",
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