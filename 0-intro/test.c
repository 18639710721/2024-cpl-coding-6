//
// Created by 2907568338 on 2024/10/21.
//

#include<stdio.h>

void rectangle() {
    for (int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_stars(int row) {
    // 这里是打印外层的行数
    for (int lines = 0; lines < row; lines++) {
        // process space  n - 1 - i
        for (int j = 0; j < row - 1 - lines; j++) {
            printf(" ");
        }

        for (int k = 0; k < 2 * lines + 1; k++) {
            printf("*");
        }

        if (lines < row -1 ){
            printf("\n");
        }

    }
}

int main(void) {

//    rectangle();
    print_stars(8);
    return 0;
}