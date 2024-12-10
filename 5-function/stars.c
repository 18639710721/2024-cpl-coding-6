//
// Created by 2907568338 on 2024/11/13.
//

#include<stdio.h>

void PrintChar(char ch, int count);

void NewLine(void);
/* 1. 实现打印任意数量特殊符号的函数并理解代码复用
 * 2. 实现换行并理解void
 *
 *
 * 当遇见大量重复的代码时，就考虑要不要封装成函数
 * 实现代码复用,因为这个打印星号和打印空格做的事情本质上
 * 是一样的，都可以看成一个打印任意数量符号的函数
 * 函数声明时候什么都不写表示不知道有多少参数
 * 函数定义时的void表示没有参数输入
 *
 * 返回值为空的函数一般不需要加一个空的return语句,
 * 有时候需要return; 提前结束函数
 * */

/*
 *  TODO: 实现打印星形金字塔
 *  考虑到这是一个二维的图形，所以外层循环要控制
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
    for (int line = 0; line < size; line++) {
        PrintChar(' ', size - 1 - line);
        PrintChar('*', 2 * line + 1);

        // 不打印第n-1个 会多一层换行
        if (line < size - 1) {
            NewLine();
        }

    }
}

void PrintChar(char ch, int count) {
    /**
     * 实现打印打印数量的特殊符号
     */
    for (int k = 1; k <= count; k++) {
        printf("%c", ch);
        return;
    }

}

void NewLine(void) {
    printf("\n");
}