//
// Created by 2907568338 on 2024/11/13.
//

#include <stdio.h>
#include <stdbool.h>

void  find_primes(int number);
bool IsPrime(int number);
/*
 * TODO: 实在判断一个区间内的数是不是素数的程序
 * [1, n]
 * 素数的定义是只能倍1和它本身整除的数是素数
 * 最朴素的想法是遍历这个序列，然后再遍历从2到n-1，
 * 判断能不能被这个数整除
 *
 * 可以做一个经典的优化
 *      在函数里面可以把标志布尔量改成
 *      return true或者false
 *
 *      函数里面允许多个return作为函数出口
 *      会在函数调用表达式里面返回一个值
 */

/*
 *
 *
 *
 */

int main() {
    find_primes(100);
}

void find_primes(int number) {
    // 遍历[1, n]
    int counter = 0;  // 计数器

    // 因为1即不是素数也不是合数
    for (int i = 2; i <= number; i++) {
        // caller 调用者
        // callee 被调用者
        if(IsPrime(i)) {
            printf("%d ", i);
            counter++;
        }

    }
    printf("\nthe numbers of prime sequence %d\n", counter);
}

bool IsPrime(int number) {

    for(int j = 2; j * j <= number; j++) {
        if (number % j == 0) {
            return false;
        }
    }

    return true;
}