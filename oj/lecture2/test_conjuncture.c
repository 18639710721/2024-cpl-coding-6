//
// Created by 2907568338 on 2024/12/26.
//
#include <stdio.h>
#include <stdbool.h>

/**
 * 考拉兹猜想
 * 第一个是计算的步骤数，第二个是计算过程中出现的最大值（含初始值）
 */

#define SIZE 1000

int main(void) {
    int maxValue = 0;
    int stepCount = 0;
    int initNum = 0;
    scanf("%d", &initNum);

    int nums[SIZE] = {0};
    nums[0] = initNum;

    int i = 0;    // 计数器
    while (true) {
        if (nums[i] == 1)
            break;

        if (nums[i] > maxValue) {
            maxValue = nums[i];
        }

        if (nums[i] % 2 == 0) {
            nums[i + 1] = nums[i] / 2;

        } else if ( nums[i] % 2 == 1) {
            nums[i + 1] = 3 * nums[i] + 1;
        }


        stepCount++;
        i++;
    }

//    for(int i = 0; i < 500; i++) {
//        printf("%d\n", nums[i]);
//    }

    printf("%d %d", stepCount, maxValue);
    return 0;
}