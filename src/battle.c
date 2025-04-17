#include "battle.h"
#include "character.h"
#include "effect_command.h"
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
    printf("%s があらわれた！\n", characters[CHARACTER_MONSTER].name);
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
                runAway();
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
                    printf("%s を倒した！\n", characters[characters[i].target].name);
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