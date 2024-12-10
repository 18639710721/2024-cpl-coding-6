//
// Created by 2907568338 on 2024/10/26.
//
#include <stdio.h>

/*
 * 1.先把if-else的框架写好
 *
 */

int main(void) {
    int a = 0;
    int b = 0;
    int c = 0;
    int min = 0;

    /*
     * 利用不等式的三歧性做条件取反判断
     * 发现三个数的最小值刚好满足四个分支的结果 不重不漏的覆盖了所有可能的结果
     */
    scanf("%d%d%d", &a, &b, &c);
    if(a < b) {
        if(a < c) {
            min = a;
        } else {   // a < b and a > c
            min = c;
        }
    } else {
        if (b < c) { // a > c and b < c
            min = b;
        } else {     // a > c abd b > c
            min = c;
        }
    }

    printf("min(%d, %d, %d) = %d", a, b, c, min);

    return 0;
}