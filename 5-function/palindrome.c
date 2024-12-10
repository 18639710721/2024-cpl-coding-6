//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// 我们仍旧不需要修改字符数组的内容 所以使用const
// 之所以这里没有写数组的长度信息，因为字符数组末尾有\0
// 编译器可以算出字符数组的长度
bool IsParlindrome(const char str[]);

#define LEN 21
char string[LEN] = "";

int main() {
    // example: nalemon
    printf("Input a string containing at most 20 char\n");
    scanf("%20s", string);

    // TODO: test palindrome
    bool is_palindrome = IsParlindrome(string);


    if (is_palindrome) {
        printf("the string is palindrome");
    } else {
        printf("the string is not palindrome");
    }
}

bool IsParlindrome(const char str[]) {

    // TODO: for version
    int len = strlen(string);
    // 循环的结束条件是i<j
    // 奇数时 等于的时候已经匹配成功了，偶数的话是i<j为true
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        if (string[i] != string[j]) {
            return false;
        }
    }
    return true;
}
