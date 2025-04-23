#include "subfunc.h"
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int power(int num, int power){
    for (int i = 0; i < power; i++){
        num *= num;
    }
    return num;
}

void printFile(const char *filename, const char *tags) {
    FILE *file = fopen(filename, "r");  // 読み込みモードで開く
    if (file == NULL) {
        printf("ストーリーが破損しています。タグ名 %s \n", tags);
        return;
    }

    char line[256];
    bool in_section = false;

    while (fgets(line, sizeof(line), file)) {
        // delete \r\n
        line[strcspn(line, "\r\n")] = 0;

        // if find tags check
        if (line[0] == '[' && line[strlen(line) - 1] == ']') {
            in_section = strcmp(line, tags) == 0;  // 一致するか確認
            continue;
        }

        // if in tags, print line
        if (in_section) {
            if (strlen(line) > 0) {
                // print line with delay
                for(int i = 0; i < strlen(line); i++){
                    printf("%c", line[i]);
                    fflush(stdout);
                    usleep(50000);  // wait 0.05 seconds
                }
                printf("\n");
            }
        }
    }
    fclose(file);
}