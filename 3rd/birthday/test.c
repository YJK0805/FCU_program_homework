#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 1024

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int i = 0;

    fp = fopen("birthday.txt", "rb");
    if (fp == NULL) {
        printf("無法打開文件\n");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // 清空輸出緩衝區，以便正確輸出中文
        fflush(stdout);

        // 移除字串中的換行符號
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }

        // 輸出讀取到的一行文字
        printf("%ls\n", line);
    }

    fclose(fp);
    return 0;
}
