#include "effect_command.h"
#include "battle.h"
#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <termio.h>
#include <unistd.h>
#include <fcntl.h>

Spell spells[SPELL_MAX] = {
    //fire
    {
        3, // consumeMP
        8, // attack
        "ファイア" // name
    },
    //heal
    {
        5, // consumeMP
        0, // attack
        "ヒール" // name
    }
};

char spellNames[SPELL_MAX][4 * 3 + 1]={
    "ファイア", // SPELL_FIRE
    "ヒール", // SPELL_HEAL
   };

void physicAttack(int attacker){
    printf("%s の攻撃！", characters[attacker].name);
    int damage = 1 + rand() % characters[attacker].attack;
    //adapt damage
    characters[characters[attacker].target].hitpoints -= damage;
    if (characters[characters[attacker].target].hitpoints < 0){
        characters[characters[attacker].target].hitpoints = 0;
        } // does not go below 0
        DrawBattleScreen();
        printf("%s に %d のダメージを与えた！\n", characters[characters[attacker].target].name, damage);
}

void spellAttack(int attacker){
    selectSpellCommand(); 
    switch (characters[attacker].command){
        case SPELL_FIRE: //fight
            spellEffect(attacker, SPELL_FIRE);
            getchar();
            break;
        case SPELL_HEAL: //spell magic
            spellEffect(attacker, SPELL_HEAL);
            getchar();
            break;
    }
}

void spellEffect(int attacker, int spellnum){
    printf("%s の攻撃！", characters[attacker].name);
    //calc damage
    characters[attacker].magicpoints -= spells[spellnum].costMP;
    if (characters[attacker].magicpoints < 0){
        characters[attacker].magicpoints = 0;
        DrawBattleScreen();
        printf("MPが、足りない！\n");
        return;
        } // does not go below 0 and attack failed
    //calc damage
        //heal func
        if (spells[spellnum].attack == 0){
            int damage = 1 + rand() % spells[spellnum].costMP;
            //adapt damage
            characters[attacker].hitpoints += damage;
            if (characters[attacker].hitpoints > characters[attacker].maxHp){
                characters[attacker].hitpoints = characters[attacker].maxHp;
                } // does not go up maxHP
                DrawBattleScreen();
                printf("%s は %d 回復した！\n", characters[attacker].name, damage);
            return;
        }
    int damage = 1 + rand() % spells[spellnum].attack;
    //adapt damage
    characters[characters[attacker].target].hitpoints -= damage;
    if (characters[characters[attacker].target].hitpoints < 0){
        characters[characters[attacker].target].hitpoints = 0;
        } // does not go below 0
        DrawBattleScreen();
        printf("%s に %d のダメージを与えた！\n", characters[characters[attacker].target].name, damage);
}


void selectSpellCommand(){
    enableRawMode();
    while (1){
        characters[CHARACTER_PLAYER].command = (SPELL_MAX + characters[CHARACTER_PLAYER].command) % SPELL_MAX;
        DrawBattleScreen();
        for (int i = 0; i < SPELL_MAX; i++){
            if (i == characters[CHARACTER_PLAYER].command){
            printf("＞"); // 選択中のコマンドなら，カーソルを描画
            }else{
            printf(" "); // 選択されていないコマンドの前に全角スペースを描画
            }
            printf("%s\n", spellNames[i]);
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