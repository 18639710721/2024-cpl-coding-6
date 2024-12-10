//
// Created by 2907568338 on 2024/11/13.
//

#include<stdio.h>

/*
 *  TODO: 实现打印星形金字塔
 *
 *      考虑到这是一个二维的图形，所以外层循环要控制
 *  打印的行数(0 ~ n-1)行, 内层分别要打印空格数量和
 *  *符号, 通过以下观察可得规律
 *  考虑到一个n-1层的金字塔 两者相加恒定为n-1
 *  n-1   0
 *  n-2   1
 *  n-3   2
 *
 *  i     n-1-i
 *
 *  2     n-3
 *  1     n-2
 *  0     n-1
 */


int main(void) {
    int size = 0;
    scanf("%d", &size);

    // 0 ~ n-1 控制外层的金字塔
    for (int row = 0; row < size; row++) {

        // 打印空格
        for (int k = 1; k <= size - 1 - row; k++) {
            printf(" ");
        }

        // 打印星号
        for (int k = 1; k <= 2 * row + 1; k++) {
            printf("*");
        }

        // 不打印第n-1个 会多一层换行
        if(row < size - 1) {
            printf("\n");
        }

    }
}