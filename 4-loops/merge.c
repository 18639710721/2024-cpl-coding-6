//
// Created by 2907568338 on 2024/11/8.
//
#include <stdio.h>

#define LEN_L 5
#define LEN_R 6

/*
 * Merge Two Sorted Arrays
 * 考虑到合并两个有序的数组,从每个数组的第一位开始比较
 *  比较结束的条件是要么l >= size 要么 r >= size
 *  即 (l >= size) or (r >= size) 恒为假
 *  真的条件取反可得 (l < size and r < size)
 *
 *  当循环结束后肯定会有一个数组还有有序的没有比较完成
 *  则使用两个循环把剩余的添加到末尾即可
 *
 */

int L_array[LEN_L] = {1, 3, 5, 7, 9};
int R_array[LEN_R] = {0, 2, 4, 6, 8, 10};


int main(void) {
    int l = 0;
    int r = 0;

    // l = size or r = size 结束循环即恒为假 取反得
    // l < size and r < size 为真的条件
    while (l < LEN_L && r < LEN_R) {
        if (L_array[l] < R_array[r]) {
            printf("%d ", L_array[l]);
            l++;
        } else {
            printf("%d ", R_array[r]);
            r++;
        }
    }

    // 循环结束后肯定有个后面是有剩余的
    while (l < LEN_L) {
        printf("%d ",L_array[l]);
        l++;
    }

    while (r < LEN_R) {
        printf("%d ", R_array[r]);
        r++;
    }

    return 0;
}