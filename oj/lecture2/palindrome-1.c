//
// Created by 2907568338 on 2024/12/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void restore_palindrome(int n, char s[]);

int main(void) {
    int num;
    scanf("%d", &num);

    char *str = (char *)malloc((num + 1) * sizeof(char)); // 动态分配字符串内存
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    scanf("%s", str);
    restore_palindrome(num, str);

    free(str);  // 释放内存
    return 0;
}

void restore_palindrome(int n, char s[]) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        if (s[left] == '?' && s[right] == '?') {
            s[left] = s[right] = 'a';  // 默认填充最小字符 'a'
        } else if (s[left] == '?') {
            s[left] = s[right];  // 用右侧字符填充左侧
        } else if (s[right] == '?') {
            s[right] = s[left];  // 用左侧字符填充右侧
        }
        left++;
        right--;
    }
    printf("%s\n", s);
}