#include "flags.h"

Flags storyFlags = {0};

void initFlags() {
    // Initialize all flags to 0
    storyFlags.started = 0;
    storyFlags.getWeapon = 0;
    storyFlags.defeatedEnemy = 0;
    storyFlags.getAlly = 0;
    storyFlags.researchCastle = 0;
    storyFlags.defeatedBoss = 0;
}

void storyProcess() {
    // Example of how to use the flags
    if (storyFlags.started == 0) {
        printf("旅立ちのときが来た！\n");
        storyFlags.started = 1;
    }
    if (storyFlags.getWeapon == 0) {
        printf("武器を手にいれた！\n");
        storyFlags.getWeapon = 1;
    }
    if (storyFlags.defeatedEnemy == 0) {
        printf("スライムをたおした！\n");
        storyFlags.defeatedEnemy = 1;
    }
    if (storyFlags.getAlly == 0) {
        printf("仲間をえた！\n");
        storyFlags.getAlly = 1;
    }
    if (storyFlags.researchCastle == 0) {
        printf("敵の本拠地についた！\n");
        storyFlags.researchCastle = 1;
    }
    if (storyFlags.defeatedBoss == 0) {
        printf("You defeated the boss!\n");
        storyFlags.defeatedBoss = 1;
    }
}

// void runEventIfFlagUnset(int flagId, void (*eventFunc)()) {
//     if (flagId < 0 || flagId >= FLAFS_MAX) {
//         return; // Invalid flag ID
//     }
//     if (storyFlags.started == 0) {
//         eventFunc();
//         storyFlags.started = 1;
//     }
// }