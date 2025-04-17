#ifndef CHARACTER.H
#define CHARACTER.H

typedef struct{
    int hitpoints; // HP
    int maxHp; // 最大 HP
    int magicpoints; // MP
    int maxMp; // 最大 MP
    char name[4 * 3 + 1]; // キャラクターの名前
    char aa[256]; // アスキーアート
   }Character;

// モンスターの種類の定義
enum{
    MONSTER_PLAYER, // プレイヤ
    MONSTER_SLIME, // スライム
    MONSTER_MAX // モンスターの種類数
   }; 

enum{
    CHARACTER_PLAYER, // プレイヤ
    CHARACTER_MONSTER, // モンスター
    CHARACTER_MAX // キャラクターの種類数
   };

extern Character characters[CHARACTER_MAX];

extern Character monsters[MONSTER_MAX];

void Init();



#endif