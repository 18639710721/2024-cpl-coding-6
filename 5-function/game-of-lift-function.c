//
// Created by 2907568338 on 2024/11/30.
//

#include <stdio.h>
#include <windows.h>

#define SIZE 6

// 感觉总体来说就是使用一个函数 实现对当前状态的更新 并且不断迭代

// int arr[]
// int arr[][N]
// goal: arr[i]; arr[i][j]

// int arr[5]
// arr[i]: the address of the first element + i * (sizeof (int))
// int arr[5][7]
// arr[2][3]
// the address of the first element +
//   2 * (number of cols * sizeof(int)) +  这里列的信息是必须的
//   3 * (sizeof (int))
// -------
// -------
// -------
// -------
// -------

// int arr[][M][N] n维数组同理
// -----------------------------------
void ExtendBoard(const int origin_board[][SIZE], int extended_board[][SIZE + 2]);

void PrintExtendedBoard(const int extended_board[][SIZE + 2]);

void GenerateNewBoard(const int old_board[][SIZE + 2], int new_board[][SIZE + 2]);

void CopyExtendedBoard(const int src_board[][SIZE + 2], int dest_board[][SIZE + 2]);

void SleepAndClear(int sec);


int main(void) {
    // init status board
    const int board[SIZE][SIZE] = {
            0, 0, 0, 0, 0, 0,
            0, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 0, 0,
            0, 0, 0, 1, 1, 0,
            0, 0, 0, 1, 1, 0,
            0, 0, 0, 0, 0,
    };
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

    int old_board[SIZE + 2][SIZE + 2] = {0};

    ExtendBoard(board, old_board);
    PrintExtendedBoard(old_board);
    SleepAndClear(1000);

    int new_board[SIZE + 2][SIZE + 2] = {0};
    for (int init_status = 1; init_status <= 10; init_status++) {
        GenerateNewBoard(old_board, new_board);
        PrintExtendedBoard(new_board);
        SleepAndClear(1000);
        CopyExtendedBoard(new_board, old_board);
    }


    return 0;
}


void ExtendBoard(const int origin_board[][SIZE], int extended_board[][SIZE + 2]) {
    // old_board(i, j) = board(i-1, j-1)
    // copy (1, row-1) (1, column) 相当于把原数组copy进更大数组
    for (int row = 1; row <= SIZE; row++) {
        for (int column = 1; column <= SIZE; column++) {
            extended_board[row][column] = origin_board[row - 1][column - 1];
        }
    }
}

void PrintExtendedBoard(const int extended_board[][SIZE + 2]) {
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            printf("%c", extended_board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

void SleepAndClear(int sec) {
    // 暂停+清除实现一帧一帧的动画效果
    Sleep(sec);
    system("cls");
}

void GenerateNewBoard(const int old_board[][SIZE + 2], int new_board[][SIZE + 2]) {
    // 2. count live neighbors for each cell
    int live_cell = 0;
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
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
            if (old_board[i][j] == 1) {
                new_board[i][j] = live_cell == 2 || live_cell == 3;
            } else {
                new_board[i][j] = live_cell == 3;
            }

        }
    }
}

void CopyExtendedBoard(const int src_board[][SIZE + 2], int dest_board[][SIZE + 2]) {
    // copy new board onto old board 将更新后的状态重置为初始状态 [0, SIZE + 2)
    for (int i = 0; i < SIZE + 2; i++) {
        for (int j = 0; j < SIZE + 2; j++) {
            dest_board[i][j] = src_board[i][j];
        }
    }
}