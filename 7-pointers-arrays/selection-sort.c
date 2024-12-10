//
// Created by 2907568338 on 2024/12/6.
//
#include <stdio.h>
#include <stdlib.h>



/*
 * 申请内存的没有free掉会造成内存泄露
 */


void SelectionSort(int arr[], int len);
void Print(const int arr[], int len);
int GetMinIndex(const int arr[], int begin, int end);
//void Swap(int arr[], int left_index, int right_index);
void Swap(int *left, int *right);


int main(void) {
    // 用户自定义数组长度

    int len = 0;
    scanf("%d", &len);

    int *numbers = malloc(len * sizeof(*numbers));

    if (numbers == NULL) {
        exit(1);
    }

    for (int i = 0; i < len; i++) {
        // &numbers[i] <=> numbers + i
        scanf("%d", &numbers[i]);
    }

    Print(numbers, len);
    // (): function-call operator
    // 在函数调用表达式中 数组名就是数组的首地址
//    SelectionSort(&numbers[0], LEN);
    SelectionSort(numbers, len);
    Print(numbers, len);


    // 申请的内存必须释放掉
    free(numbers);
}

// arr = &numbers[0]  int *
int GetMinIndex(const int *arr, int begin, int end) {
    int min_index = begin;\
    // 在闭区间[begin, end] 搜索 即 [begin, LEN-1]
    for(int i = begin; i <= end; i++) {
        // int *
        // 数组名是首地址 它也是一个指针 但不是指针变量
        // 在编译器眼中 arr[i] 只是指针操作的语法糖 背后其实都是指针
        // arr[i]: *(arr + i) <=> *(i + arr) <=> i[arr]
        // p + i, p - i, p - q
        if(arr[i] < arr[min_index]) {
            min_index = i;
        }
    }
    printf("%d\n", min_index);
    return min_index;
}

void Print(const int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// left = &arr[min_index]  right = &arr[i]
// *left 等价于 arr[i]
// *right 等价于 arr[min_index]
void Swap(int *left, int *right) {
    int temp = *left;
    *left = *right;
    *right = temp;
}



// numbers: &numbers[0] int *类型
// 在参数中，int[]只是int*的语法糖 本质就是int*
// int *arr = &numbers[0]
void SelectionSort(int *arr, int len) {
    for (int i = 0; i <= len - 1; i++) {
        // type: int * arr
        int min_index = GetMinIndex(arr, i, len - 1);
        // &arr[i] <=> &(*(arr + i)) <=> arr + i
        Swap(arr + min_index, arr + i);

    }

}