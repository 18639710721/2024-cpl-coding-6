//
// Created by 2907568338 on 2024/11/8.
//

#include<stdio.h>
#include <stdlib.h>
#include <windows.h>

#define SIZE 6

/*
 * TODO: 实现生命游戏(元胞自动机)
 * Rules:
 *  而生命游戏就是最简单的元胞自动机之一——在二维平面上的方格子（细胞），每个细胞有两种状态：死或活，
 *  而下一回合的状态完全受它周围8个细胞的状态而定。按照以下三条规则进行演化：
 *     1. 活细胞周围的细胞数如果小于2个或多于3个则会死亡；（离群或过度竞争导致死亡）
 *     2. 活细胞周围如果有2或3个细胞可以继续存活；（正常生存）
 *     3. 死细胞（空格）周围如果恰好有3个细胞则会诞生新的活细胞。（繁殖）
 *  实现步骤
 *     默认6x6方格
 *     默认存活为'*'
 *     死亡为’ ‘(空格)
 *     游戏的 init status(初始状态)
 *      **
 *      **
 *        **
 *        **
 *
 *     根据周围方格迭代状态
 *
 *     1.因为每一个格子生存还是死亡取决于周围八个格子的状态，所以要处理外围格子的边界情况
 *          1x1方格 --> 3x3方格
 *          2x2方格 --> 4x4方格
 *          ixj方格 --> (i+2)x(j+2)方格
 *      所以初始化全为0的8x8方格old_board,
 *      并copy初始状态并打印输出查看
 *
 *     2.根据周围8个方格的状态更新一次状态,所以要根据board[i][j]去进行八次逻辑判断
 *     然而可以观察并简化表达式,并把更新数据存入新的new_board
 *
 *     3.实在这个迭代状态的刷新 即应用游戏规则
 *       1. 活细胞周围的细胞数如果小于2个或多于3个则会死亡；（离群或过度竞争导致死亡）
 *       2. 活细胞周围如果有2或3个细胞可以继续存活；（正常生存）
 *       3. 死细胞（空格）周围如果恰好有3个细胞则会诞生新的活细胞。（繁殖）
 *       f(old_board) -> new_board
 *       f(new_board) -> new_board'
 *       f(new_board') -> new_board''
 *       通过观察后把迭代后的数据更新到old_board即可
 *       通过两层循环实现
 *
 *    4.观察到可以将顺序打印的图案看出一帧一帧动画
 *    如果借助system("cls")的清屏效果会太快了，
 *    使用sleep()使画面暂停一小会即可造成画面一直在改变的感觉
 *
 */


// init status board
const int board[SIZE][SIZE] = {
        0, 0, 0, 0, 0, 0,
        0, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 0, 0,
        0, 0, 0, 1, 1, 0,
        0, 0, 0, 1, 1, 0,
};

int main(void) {

    // 初始化全部置0
    int old_board[SIZE + 2][SIZE + 2] = {0};

    // extend this board
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            old_board[i][j] = board[i - 1][j - 1];
        }
    }
    for (int i = 1; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            printf("%c ", old_board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
    system("cls");

    int new_board[SIZE + 2][SIZE + 2] = {0};

    for (int k = 0; k < 1000; k++) {
        // 更新游戏状态
        int counter = 0;
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {

                if (old_board[i - 1][j - 1] == 1) {
                    counter++;
                }
                if (old_board[i - 1][j] == 1) {
                    counter++;
                }
                if (old_board[i - 1][j + 1] == 1) {
                    counter++;
                }
                if (old_board[i][j - 1] == 1) {
                    counter++;
                }
                if (old_board[i][j + 1] == 1) {
                    counter++;
                }
                if (old_board[i + 1][j - 1] == 1) {
                    counter++;
                }
                if (old_board[i + 1][j] == 1) {
                    counter++;
                }
                if (old_board[i + 1][j + 1] == 1) {
                    counter++;
                }

                // 细胞存活的状态
                if (old_board[i][j] == 1) {

                    // 当细胞活着，周围有两个或者三个存活时依旧活着
                    if (counter == 2 || counter == 3) {
                        new_board[i][j] = 1;
                    }

                    // 因孤独或者拥挤而死亡
                    if (counter < 2 || counter > 3) {
                        new_board[i][j] = 0;
                    }

                }

                // 细胞死亡的状态
                if (old_board[i][j] == 0) {
                    if (counter == 3) {
                        new_board[i][j] = 1;
                    } else {
                        new_board[i][j] = 0;
                    }
                }
                // 检查一格后重置为0以便于检查下一格
                counter = 0;
            }
        }

        // print the new board
        // 打印更新后新的棋盘, 即原6*6棋盘
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                printf("%c ", new_board[i][j] ? '*' : ' ');
            }
            printf("\n");
        }

        // 把一帧一帧的画面打印出来
        Sleep(100);

        system("cls");
        // 为了迭代 将得到的结果赋值为old_board，方便进行下一次迭代
        for (int i = 0; i < SIZE + 2; i++) {
            for (int j = 0; j < SIZE + 2; j++) {
                old_board[i][j] = new_board[i][j];
            }
        }
    }

    return 0;
}