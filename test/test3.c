//
// Created by 2907568338 on 2024/11/24.
//
#include <stdio.h>

#define SIZE 5

int main(void) {

    int numbers[SIZE] = {0} ;

    for(int i = 0; i < SIZE; i++) {
        numbers[i] = i;
    }
    numbers[6] = 3;

    for(int i = 0; i < SIZE; i++) {
        printf("%d ",numbers[i]);
    }

    return 0;
}