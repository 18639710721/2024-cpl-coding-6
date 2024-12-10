//
// Created by 2907568338 on 2024/11/5.
//
#include <stdio.h>

int main(void) {
    // 为了避免头重脚轻的arrow code 对条件取反进行优化一下
    // 随便对本案例并不是那么有效,说不定对其他会很有效

    // 当if-else后面只有一条语句时 可以把{}去掉
    // 优化后的称之为级联式的if else if
    int year = 0;
    int leap = 0;

    scanf("%d", &year);

    if (year % 4 != 0) {
        leap = 0;
    } else if (year % 100 != 0) {
        leap = 1;
    } else if (year % 400 != 0) {
        leap = 0;
    } else {
        leap = 1;
    }

    if (leap == 0) {
        printf("%d is common year", year);
    } else {
        printf("%d is leap year", year);
    }


    return 0;
}