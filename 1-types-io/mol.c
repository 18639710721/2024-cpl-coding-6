//
// Created by 2907568338 on 2024/10/22.
//
#include <stdio.h>

/*
 * %[flags][width][.[precision]]specifier
 */

int main(void) {
    // 摩尔是一个常量 用科学计数法E表示
    const double MOL = 6.02E23;
    const int GRAM_PER_MOL = 32;

    int mass = 6;

    // 这里使用乘1.0的技巧变成浮点数乘法
    double quantity = 1.0 * mass / GRAM_PER_MOL * MOL;

    // %e: exponent 科学计数法 .3 精度
    // %g: significant .5g 输入double类型根据大小按%f或%e输出
    printf("quantity = %.3e\nquantity = %.5g\n", quantity, quantity);


    return 0;
}