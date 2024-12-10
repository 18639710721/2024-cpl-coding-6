//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>

// file scope 全局作用域的变量是很危险的
int BinarySearch(int key, const int dict[], int len);

/*
 * 当个一个数组名在函数调用表达式里面的时候，会自动被转
 * 成数组首地址的类型
 *
 * file scope 全局作用域的变量是很危险的，一般来说
 * 作用域越小越好，越容易控制
 *
 * const 调用者希望实现者内部没有修改数组
 * 数组一开始声明const的话更强大,比函数里面的限制性更强
 *
 *
 *
 */

#define LEN 10

int main(void) {
    int const dictionary[LEN] = {1, 1,2, 3, 5, 8, 13, 21,34, 55};

    int key = 0;
    scanf("%d", &key);

    // dictionary: const int[]
    // dict: int[]   传参的时候类型不一致
    // 这里的dictionary会被解析为指向数组第一个元素的指针
    int index = BinarySearch(key, dictionary, LEN);
    if (index == -1) {
        printf("Not find");
    } else {
        printf("the index of number is %d", index);
    }
}
// dict: int[], const int[]
// int dict the address of the first element
// 指向一个int类型元素的指针，存着数组第一个元素的地址
// 传递进来数组的首地址, 并且加上长度信息

// int[] incomplete type 所以这是一个不完整类型
// int dict[5]
// 会转换成一个指针,大小信息被擦除了
int BinarySearch(int key, const int dict[], int len) {
    // TODO: binary search: search for key in dictionary
    int low = 0;
    int high = len - 1;


    while (low <= high) {
        int mid = (low + high) / 2;
        if (dict[mid] == key) {
            return mid;
        } else if (dict[mid] > key) {
            high = mid - 1;
        } else if (dict[mid] < key) {
            low = mid + 1;
        }
    }
    return -1;
}