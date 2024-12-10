//
// Created by 2907568338 on 2024/12/6.
//
#include <stdio.h>

#define LEN 6

/*
 * pass by value
 *     C语言中函数参数传递的本质是传值,
 *     传地址也是传值, 只不过值有点特殊 是address
 */


void SelectionSort(int arr[], int len);
void Print(const int arr[], int len);
int GetMinIndex(const int arr[], int begin, int end);
void Swap(int arr[], int left, int right);


int main(void) {
    int  numbers[LEN] = {89, 20, 50, 30 , 70, 10};

    Print(numbers, LEN);
    SelectionSort(numbers, LEN);
    Print(numbers, LEN);

}

int GetMinIndex(const int arr[], int begin, int end) {
    int min_index = begin;\
    // 在闭区间[begin, end] 搜索 即 [begin, LEN-1]
    for(int i = begin; i <= end; i++) {
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

void Swap(int arr[], int left, int right) {
    /*
     * 因为这个数组是拿到的是实参的首地址
     * 所以可以访问到数组里的数据
     *
     * 如果没有写则只是交换了copy的值
     */
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;


}

void SelectionSort(int arr[], int len) {
    for (int i = 0; i <= LEN - 1; i++) {
        int min_index = GetMinIndex(arr, i, LEN - 1);
        Swap(arr, i, min_index);

    }

}