//
// Created by 2907568338 on 2025/1/16.
//

#include <stdio.h>
#define SIZE 30
/*
 * 1.求斐波那契数列通项(特征根法) 构造等比数列
 * 2.递归求解斐波那契数列
 * 3.递推求解斐波那契数列
 * 4.记忆化搜索求解斐波那契数列
 * 5.动态规划求解斐波那契数列
 * 6.矩阵快速幂求解
 *
 */

int FibRecursive(int n);
int FibRecurMemo(int n);
int FibDp(int *fib_seq, int size);



int main(void) {
    // 我这里定义的斐波那契数列默认是从第0项开始数的
    for (int i = 1; i < 20; i ++) {
        printf("%d\n", FibRecursive(i));
    }
    printf("\n");
    int fib_seq[SIZE] = {0};
    FibDp(fib_seq, SIZE);
    int *ptr = fib_seq;
    for (int i = 0; i < SIZE; i++) {
        printf("%d\n", *(ptr + i));
    }
    printf("%d", ptr[0]);
    printf("\n");
    printf("%d", FibRecurMemo(10));
    return 0;
}
int FibRecursive(int n) {
    // 0 1 1 2 3 5
    return n < 3 ? 1 : FibRecursive(n - 1) + FibRecursive(n - 2);
}

int FibDp(int *fib_seq, int size) {
    fib_seq[0] = 0;
    fib_seq[1] = 1;
    for (int i = 2; i < size; i++) {
        fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
    }
}

int FibRecurMemo(int n) {
    // 记忆化搜索 使用一个数组储存值解决掉重复计算
    // 每次递归返回函数值之前检查一下数组中是否有即可
    // 这里有问题不想解决了
    int fib_memo[5] = {-1};
    fib_memo[0] = 0;
    fib_memo[1] = 1;
    if (fib_memo != -1) {
        return fib_memo[n];
    } else {
        int result = FibRecurMemo(n - 1) + FibRecurMemo(n - 2);
        fib_memo[n] = result;
        return result;
    }

}