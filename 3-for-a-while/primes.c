//
// Created by 2907568338 on 2024/11/13.
//

#include <stdio.h>

void  find_primes(int number);
/*
 * TODO: 实在判断一个区间内的数是不是素数的程序
 * [1, n]
 * 素数的定义是只能倍1和它本身整除的数是素数
 * 最朴素的想法是遍历这个序列，然后再遍历从2到n-1，
 * 判断能不能被这个数整除
 */

/*
 *
 *
 *
 */

int main() {
    find_primes(100);
    find_primes(1000);
    find_primes(10000);


}

void find_primes(int number) {
    // 遍历[1, n]
    int counter = 0;  // 计数器

    // 因为1即不是素数也不是合数
    for (int i = 2; i <= number; i++) {
        // 设置一个标志 判断是否满足素数的定义
        int flag = 1;

        // 判断从2到n-1区间内的数能不能整除n  [2, i-1]

        for (int factor = 2; factor <= i - 1; factor++) {
            if (i % factor == 0) {
                flag = 0;
                break;   // break 只会跳出最近的内层循环
            }
        }
        if(flag == 1) {
            printf("%d ", i);
            counter++;
        }

    }
    printf("\nthe numbers of prime sequence %d\n", counter);
}