#include <stdio.h>
#include <string.h>
#include <malloc.h>
int main(int argc, char* argv[]) {
    if (argc == 3) {
        char* content = (char*)malloc(300 * sizeof(char));
        int n = 0;
        FILE* f;
        errno_t err;
        if ((err = fopen_s(&f, argv[2], "r")) != 0) {
            printf("文本文件不存在");
            return -1;
        }
        else {
            char c;
            while ((c = fgetc(f)) != EOF) {
                *(content + n++) = c;
            }
            *(content + n) = '\0';
            fclose(f);
        }
        if (strcmp(argv[1], "-c") == 0) {
            int j;
            for (j = 0; content[j] != '\0'; j++);
            printf("字符数:%d", j);
        }
        else if (strcmp(argv[1], "-w") == 0) {
            int temp = 0, j, count = 0;
            for (j = 0; content[j] != '\0'; j++) {
                if (content[j] == ' ' || content[j] == '\n' || content[j] == ',') {
                    if (temp != 0) {
                        temp = 0;
                        count++;
                    }
                }
                else {
                    temp = 1;
                }
            }
            printf("单词数:%d", count + 1);
        }

    }
    else {
        printf("输入的参数不对");
    }
}

