#ifndef CHARACTER_H
#define CHARACTER_H
#define MONSTER_START_INDEX 1
#define MONSTER_COUNT 2

typedef struct{
    int hitpoints; // HP
    int maxHp; // 最大 HP
    int magicpoints; // MP
    int maxMp; // 最大 MP
    int attack; // 攻撃力
    char name[5 * 3 + 1]; // キャラクターの名前
    char aa[256]; // アスキーアート
    int command; // 選択中のコマンド
    int target; // 攻撃対象
   }Character;

// モンスターの種類の定義
enum{
    MONSTER_PLAYER, // プレイヤ
    MONSTER_SLIME, // スライム
    MONSTER_MADHAND, //マドハンド
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