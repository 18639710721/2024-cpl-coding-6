//
// Created by 2907568338 on 2024/11/30.
//

#include <stdio.h>
#include <windows.h>

#define SIZE 6

// 感觉总体来说就是使用一个函数 实现对当前状态的更新 并且不断迭代

// init status board
const int board[SIZE][SIZE] = {
        0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 0, 0,
        0, 0, 0, 1, 1, 0,
        0, 0, 0, 1, 1, 0,
        0, 0, 0, 0, 0,
};

void print_board(int boards[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main(void) {

    // TODO: implement the game of life
//    print_board(board);

    // 1. expand this board
    // Matrix(i, j) --> Matrix(i + 2, j + 2)  为了考虑边界条件

    /*
     * [0]    ->  [1]     size 1
     * [0, 1] ->  [1, 2]  size 2
     * [0, 1, 2] -> [1, 2, 3] size 3
     * [0, size - 1] -> [1, size]  闭区间
     * [0, 5] -> [1, 6]  所以在1到6区间循环
     */
    // copy (1, row-1) (1, column) 相当于把原数组copy进更大数组
    int old_board[SIZE + 2][SIZE + 2] = {0};

    // old_board(i, j) = board(i-1, j-1)
    for (int row = 1; row <= SIZE; row++) {
        for (int column = 1; column <= SIZE; column++) {
            old_board[row][column] = board[row - 1][column - 1];
        }
    }

//    for (int i = 0; i < SIZE + 2; i++) {
//        for (int j = 0; j < SIZE + 2; j++) {
//            printf("%d ", old_board[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");

    // print charter  打印字符 黑白 01 只要是相对的即可 [1, SIZE]
    // 最初始的状态 一个周期为2的图形
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            printf("%c", old_board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }

    for (int init_status = 1; init_status <= 10; init_status++) {
        // 2. count live neighbors for each cell
        int live_cell = 0;
        int new_board[SIZE + 2][SIZE + 2] = {0};
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                // 处理这种如果表达成立 就加一 否则 就加零
                // 可以直接当加表达式的值即可
                live_cell =
                        old_board[i - 1][j - 1] +
                        old_board[i - 1][j] +
                        old_board[i - 1][j + 1] +
                        old_board[i][j - 1] +
                        old_board[i][j + 1] +
                        old_board[i + 1][j - 1] +
                        old_board[i + 1][j] +
                        old_board[i + 1][j + 1];

                // 3. apply rule implement f update current status
                // 又出现了如果表示成立等于1 不成立等于0的逻辑
//            if (old_board[i][j] == 1) {
//                if (live_cell == 2 || live_cell == 3) {
//                    // 存活 合适的生存环境
//                    new_board[i][j] = 1;
//                } else {
//                    // 拥挤或者离群索居会导致死亡
//                    new_board[i][j] = 0;
//                }
//            } else {
//                if (live_cell == 3) {
//                    // 模拟生命的繁殖
//                    new_board[i][j] = 1;
//                } else {
//                    new_board[i][j] = 0;
//                }
//            }

                // 优化后的上列代码
                if(old_board[i][j] == 1) {
                    new_board[i][j] = live_cell == 2 || live_cell == 3;
                } else {
                    new_board[i][j] = live_cell == 3;
                }

            }
        }
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                printf("%c", new_board[i][j] ? '*' : ' ');
            }
            printf("\n");
        }
        // 暂停+清除实现一帧一帧的动画效果
        Sleep(1000);
        system("cls");

        // copy new board onto old board 将更新后的状态重置为初始状态 [0, SIZE + 2)
        for (int i = 0; i < SIZE + 2; i++) {
            for (int j = 0; j < SIZE + 2; j++) {
                old_board[i][j] = new_board[i][j];
            }
        }
    }


    return 0;
}