//
// Created by 2907568338 on 2024/12/20.
//
#include <stdio.h>

#define SIZE 5

int main(void) {
    const int coinValues[SIZE] = {50, 20, 10, 5, 1};
    int coinCounts[SIZE] = {0};
    int targetSum = 0;
    scanf("%d", &targetSum);

    for(int i = 0; i <= 4; i++) {
        int t = targetSum / coinValues[i];
        targetSum -= t * coinValues[i];
        coinCounts[i] = t;
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d\n", coinCounts[i]);
    }
    return 0;
}