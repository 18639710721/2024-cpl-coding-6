//
// Created by 2907568338 on 2024/11/6.
//
#include <stdio.h>

// Macro(宏) SIZE是这个常数的替代
// 在编译器编译这个程序的时候，有个预处理阶段,
// 会把所有的SIZE替换成常量
#define SIZE 10000
/*
 * TODO: implement find the min of the array
 *      for loop 的语义和语法 熟悉这个过程
 *      VLA可以用Macro(宏)去代替
 *
 *      #define SIZE 10000
 *          在编译器编译这个程序的时候，有个预处理阶段,
 *          会把所有的SIZE替换成常量
 * Array Initializer
 *      int numbers[NUM] = {1}; 假设NUM为5的话后面都会被默认为0
 *      int numbers[] = {0, 1, 2} 编译器会根据后面大小填入 推荐做法
 *      int numbers[NUM] = {[1] = 1} 根据下标赋值
 *      总之，没有写得会被编译器自动赋0
 *
 *      int numbers[]; Don't
 *      You must specify the size so that the compiler/runtime
 *      can allocate memory for it.
 *
 *
 */


int main() {
    // TODO: implement find the min of the array
    // min(23, 56, 19, 11, 78) = min(min(min(min(23, 56), 19), 11), 78) 需四次迭代
    // type: int[5] (not int[], not int)
    // int[5] vs int[3]
    // 数组的大小是它类型信息的一部分 int[5]和int[3]显然是不同的

//    const int SIZE = 5;
    // int numbers[5]: array of known size
    // int numbers[SIZE] 编译器并不知道如何分配内存以及初始化
    // variable-length array (VLA)

    // 后面没有写的都会是0
    int numbers[SIZE] = {23, 89, 77, 12, 25};

    // []: array subscript operator
    int min = numbers[0];

    // syntax 语法
    // (1): init-clause   int i = 1 只做一次
    // (2): cond-expression
    // (3): iteration-expression increment 计数器
    // (4): loop-statement (loop body)
    // 243 构成了一个循环

    // semantic 语义过程
    // iter 0: i = 1 init-clause i < 5
    // iter 1: numbers[1] = 89 vs min = 23; min = 23; i = 2 i < 5
    // iter 2: numbers[2] = 77 vs min = 23; min = 23; i = 3 i < 5
    // iter 3: numbers[3] = 12 vs min = 23; min = 12; i = 4 i < 5
    // iter 4: numbers[4] = 25 vs min = 12; min = 12; i = 5
    // terminate the loop

    for (int i = 1; i < 5; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }

    printf("min=%d", min);
    return 0;
}
