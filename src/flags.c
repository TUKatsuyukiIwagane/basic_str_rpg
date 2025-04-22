#include "flags.h"

Flags storyFlags = {0};

void initFlags() {
    // Initialize all flags to 0
    storyFlags.started = 0;
    storyFlags.kingAppeared = 0;
    storyFlags.defeatedSlime = 0;
    storyFlags.getWeapon = 0;
    storyFlags.getVillage = 0;
    storyFlags.warriorAppeared = 0;
    storyFlags.defeatedEnemy = 0;
    storyFlags.getAlly = 0;
    storyFlags.researchCastle = 0;
    storyFlags.defeatedBoss = 0;
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