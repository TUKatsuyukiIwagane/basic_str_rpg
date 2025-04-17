#ifndef EFFECT_COMMAND_H
#define EFFECT_COMMAND_H

enum{
    SPELL_FIRE, //attack spell
    SPELL_FULLPOWER, //attack spell
    SPELL_HEAL, //heal spell
    SPELL_MAX // amount of spell
   }; 

typedef struct{
    int costMP; // consume MP
    int attack; // 攻撃力
    char name[5 * 3 + 1]; // spell name
   }Spell;


void physicAttack(int attacker);
void spellAttack(int attacker);
void spellEffect(int attacker , int spellnum);
void selectSpellCommand();
void runAway();

#endif