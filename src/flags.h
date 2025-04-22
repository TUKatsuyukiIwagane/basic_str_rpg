#ifndef FLAGS_H
#define FLAGS_H
#define FLAFS_MAX 100

typedef struct {
    int started;
    int kingAppeared;
    int getWeapon;
    int defeatedEnemy;
    int getAlly;
    int researchCastle;
    int defeatedBoss;
} Flags;

extern Flags storyFlags;



void initFlags();
// void runEventIfFlagUnset(int flagId, void (*eventFunc)());
void checkEvent(int flagId, void (*eventFunc)());

#endif