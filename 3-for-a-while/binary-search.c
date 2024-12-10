//
// Created by 2907568338 on 2024/11/13.
//
#include <stdio.h>

#define LEN 10
int dictionary[LEN] = {1, 1,2, 3, 5, 8, 13, 21,34, 55};

int main(void) {
    int key = 0;
    scanf("%d", &key);

    // TODO: binary search: search for key in dictionary

    int low = 0;
    int high = LEN - 1;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (dictionary[mid] == key) {
            index = mid;
            break;
        } else if (dictionary[mid] > key) {
            high = mid - 1;
        } else if (dictionary[mid] < key) {
            low = mid + 1;
        }
    }

    if (index == -1) {
        printf("Not find");
    } else {
        printf("the index of number is %d", index);
    }
}