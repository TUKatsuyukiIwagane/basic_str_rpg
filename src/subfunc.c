#include "subfunc.h"

int power(int num, int power){
    for (int i = 0; i < power; i++){
        num *= num;
    }
    return num;
}

void printFile(const char *filename) {
    FILE *file = fopen(filename, "r");  // 読み込みモードで開く
    if (file == NULL) {
        printf("ファイル %s を開けませんでした。\n", filename);
        return;
    }

    char line[256];  // 1行ごとのバッファ
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);  // fgets は改行も含むので printf("%s")でOK
    }

    fclose(file);
}