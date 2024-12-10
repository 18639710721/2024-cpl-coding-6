//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>
/*
 * 将10以下的数字除10 按一位进行特殊处理以避免边界条件0
 *  number /10 != 0 二位即以上
 */

int main() {
    int number = 0;

    scanf("%d", &number);

    // 一位数字都默认为1
    // 循环条件当两位数后才进行处理
    int  num_of_digits = 1;
    for(; number / 10 != 0; num_of_digits++) {
        number /= 10;
    }
    printf("the digits of number is %d", num_of_digits);


    return 0;
}