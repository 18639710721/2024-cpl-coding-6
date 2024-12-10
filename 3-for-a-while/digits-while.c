//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>
/*
 * TODO: number of digits
 * 可以把一个任意位数的数字按权展开
 * 会发现一直除以10之后除位数次后肯定得0,
 * 感觉有可能是带余除法原理的原因，
 *
 * 因为有0这个特殊值的存在，所以考虑用do-while循环
 * 先执行一次程序
 *
 */

int main(void) {
    int number = 0;
    int  num_of_digits = 0;  // 计数器 用于记录位数
    scanf("%d", &number);

    // 注意处理边界条件0
    if (number == 0) {
        num_of_digits++;
    }
    while (number > 0) {
        number /= 10;
        num_of_digits++;
    }

    printf("Number of digits is %d\n", num_of_digits);
    return 0;
}