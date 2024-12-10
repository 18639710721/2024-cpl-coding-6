//
// Created by 2907568338 on 2024/10/26.
//
#include <stdio.h>

// int overflow 溢出
int main() {
    // TODO calculate the minimum of a and b
    int a = 0, b = 0;
    int min = 0;
    scanf("%d%d", &a, &b);
//    if (a < b) {
//        min = a;
//    } else {
//        min = b;
//    }

    // 三目运算符  简化if else 这个运算符可以构成一个表达式(有值的)
    // min = a >= b ?b : a;
    min = a >= b ? b : a;

    printf("min(%d, %d) = %d", a, b, min);


}