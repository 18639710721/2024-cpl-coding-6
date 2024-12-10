//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>
/*
 * 为了处理0的边界条件 使用do-while
 * do {
 *  } while(expression);
 * 语义是无论发生什么都会执行一次
 */

int main() {
    int number = 0;
    int digits_of_number = 0;

    scanf("%d", &number);

    do {
        number /= 10;
        digits_of_number++;
    } while(number > 0);

    printf("the digits of number is %d", digits_of_number);
    return 0;
}