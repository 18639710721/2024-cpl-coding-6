//
// Created by 2907568338 on 2024/12/10.
//
#include <stdio.h>

// 不包含\0的字符的个数

int main(void) {
    // char msg[] = { 'H', 'e', ..., '!', '\0' };
    char msg[] = "Hello World!";
    msg[0] = 'N';
    printf("%s\n", msg);

    char *ptr_msg = "Goodbye World!";
    // Signal: SIGSEGV (Segmentation fault) violation 违反
    // 经常做指针题目要注意
    // 这里发生错误是因为访问了text 只读区
    // 存放 constants string liberals
    ptr_msg[0] = 'N';
    printf("%s\n", msg);

    return 0;
}