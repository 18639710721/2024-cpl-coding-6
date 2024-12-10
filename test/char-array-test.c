//
// Created by 2907568338 on 2024/12/9.
//
#include <stdio.h>


int main(void) {
    //
//    char *str = "abc";
    char str[] = "abc";

    int len = sizeof str / sizeof(str[0]);
    printf("%d\n", len);
    for (int i = 0; i < len; ++i) {
        if(str[i] == '\0') {
            printf("[\\0]\n");
            printf("ASCII of '\\0': %d\n", str[i]);
            printf("ASCII of '\\0': %d\n", str[len - 1]);
        }
        printf("%c", str[i]);

    }
    printf("%p\n", str);
    printf("%c\n", *str);
    printf("%c",str[10]);


    return 0;
}
