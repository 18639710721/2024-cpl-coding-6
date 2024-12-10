//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define LEN 21
char string[LEN] = "";

int main() {
    // example: nalemon
    printf("Input a string containing at most 20 char\n");
    scanf("%20s", string);

    // 可以使用string.h的strlen函数实现
//    int len = 0;
//    while (string[len] != '\0') {
//        len++;
//    }

    int len = strlen(string);

    printf("The length of \"%s\" is %d. \n", string, len);

    // TODO: test palindrome

    bool is_palindrome = true;
    // TODO: for version

    // 循环的结束条件是i<j
    // 奇数时 等于的时候已经匹配成功了，偶数的话是i<j为true
//    for(int i = 0, j = len - 1; i < j; i++, j--) {
//        if (string[i] != string[j]) {
//            is_palindrome = false;
//            break;
//        }
//    }


    // TODO: while version
    int i = 0, j = len - 1;
    while (i < j) {
        if (string[i] != string[j]) {
            is_palindrome = false;
            break;
        }
        i++;
        j--;
    }


    if(is_palindrome) {
        printf("the string is palindrome");
    } else {
        printf("the string is not palindrome");
    }
}