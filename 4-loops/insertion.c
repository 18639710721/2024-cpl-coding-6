//
// Created by 2907568338 on 2024/11/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEN 10000
#define RANGE 10

int main(void) {

    int numbers[MAX_LEN] = {0};

    int size = 0;
    scanf("%d", &size);

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        numbers[i] = rand() % RANGE;
    }

    // print the original array
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    printf("\n");

    // 打印插入排序后的数组
    // n-1趟即可排序完成
    for (int i = 1; i < size; i++) {

    }


    // print sorted array
    for(int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
