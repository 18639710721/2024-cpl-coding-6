//
// Created by 2907568338 on 2024/10/22.
//

#include <stdio.h>
#include <math.h>

/*
 * %[flags][width][.[precision]]specifier
 */

void compute_sphere_prime_version() {
    // C语言的除法如果操作数都是整数 商也是整数(封闭的)
    // 但是会影响精度 可以把范围限制在浮点数中

    int radius = 100;
    double surface_area = 4 * 3.14159 * radius * radius;
    double volume = 4.0 / 3 * 3.14159 * radius * radius * radius;

    // 15: field width 最少占15个字符
    //-: 默认是右对齐 这里设置为左对齐
    printf("%-15.4f : surface_area\n%-15.4f : volume\n", surface_area, volume);
}

/*
 * 1.pi要多次复用 所以要赋值给变量使用    declare
 *   pi是一个常量，最好我们声明后不能再修改 用const 常量一般大写
 *
 * 2.使用pow()简洁表达式
 */

void compute_sphere_modify_version() {
    const double  PI = 3.14159;
    int radius = 100;
    double surface_area = 4 * PI * pow(radius, 2);
    double volume = 4.0 / 3 * PI * pow(radius, 3);

    // 15: field width 最少占15个字符
    //-: 默认是右对齐 这里设置为左对齐
    printf("%-15.4f : surface_area\n%-15.4f : volume\n", surface_area, volume);
}

/*
 * 为了代码的健壮性和可移植性，可以在cake文件手动链接库
 */

int main() {
    compute_sphere_prime_version();
    compute_sphere_modify_version();
    return 0;
}