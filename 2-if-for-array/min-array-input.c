//
// Created by 2907568338 on 2024/11/6.
//
#include <stdio.h>

#define SIZE 10000

/*
 * 实现一个读取用户输入数组长度及数字的程序
 *      size
 *      size个数字
 */

int main() {
    int size = 0;
//    int array[size] = {0};
// 这里并不能使用变长数组 所以用define声明一个比较大的数组即可
    int numbers[SIZE] = {0};    // 默认全部都赋值为0

    scanf("%d\n", &size);

    for (int i = 0; i < size; i++) {
        // 读取size个数字
        // numbers[i] as a variable
        // 这个表达式可以当成变量(一块内存空间),可以进行取地址 赋值 读值等操作
        scanf("%d", &numbers[i]);


    }

    int min = numbers[0];
    // 需要size-1次迭代
    for (int i = 1; i < size; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("min=%d\n", min);

    return 0;
}