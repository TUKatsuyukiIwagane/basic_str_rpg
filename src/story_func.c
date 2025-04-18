#include "story_func.h"
#include "flags.h"
#include "subfunc.h"
#include <stdio.h>

void storyProcess() {
    // Example of how to use the flags
    if (storyFlags.started == 0) {
        printFile("story_start.txt");
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
        printf("ボスをたおした！!\n");
        storyFlags.defeatedBoss = 1;
    }
}