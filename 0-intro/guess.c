//
// Created by 2907568338 on 2024/10/15.
//
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


/* windows 控制台支持显示 utf8 编码的中文字符 */
/*输入中文乱码的解决方案 https://zhuanlan.zhihu.com/p/531460693*/
void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

/*
 * 顺序语句 + 条件选择语句 + 循环语句 理论上可以构造任何程序
 */

int main(void) {
    windows_cmd_support_utf8();

    /*
     * print the rule of the game
     */

    int max = 100;     // 猜数字游戏的上界 upper bound
    int tries = 7;      // 默认有七次猜测的机会，可以当成循环结束的终止条件
    int guess_number = 0;   // 默认初始值为 0 用于存储用户输入的数字
    printf("用户你有%d次猜测机会\n", tries);
    printf("本次游戏的数字范围是0到%d\n", max);
    /*
     * generate a random number
     * 伪随机(计算机世界) 和真随机(物理世界)
     * x, f(x), f(f(x)), ... 伪随机序列  x是随机数种子，也就是第一个数字
     * 某个函数f迭代得到随机数序列(伪随机序列) 比如平方取中法和线性同余算法
     * 因为伪随机序列是可预测，为了增加随机性，就使用当前系统的时间戳作为随机数种子
     * 安全编码的概念 :华为的c语言手册中在用于安全用途禁用该函数
     */
    srand(time(NULL)); // use current time as seed for random generator
    int random_variable = rand();

    int secret = random_variable % max + 1;  // 利用模运算的有界性限制随机数的大小

    /*
     *  let the player enter his/her guess number
     */

    // 循环就是考虑一些重复执行的代码
    while (tries > 0) {

        tries--;                  // 每次进入循环 猜测机会减一

        printf("该次游戏运行生成的随机数是%d\n", secret);
        /*
         * store the guess number,
         * compare it with the secret,
         * and inform the player of the result
         */
        scanf("%d", &guess_number);

        if (guess_number == secret) {
            printf("你赢了\n");
            break;   // 当满足胜利条件时候，终止循环
        } else if (guess_number > secret) {
            printf("guess_number > secret\n");
            printf("您还有%d次机会\n", tries);
        } else {
            printf("guess_number < secret\n");
            printf("您还有%d次机会\n", tries);
        }

        /*
         * loop: repeat until the player wins or loses
         */
//        tries = tries - 1;

    }

    // 通过分析发现游戏的失败条件为猜测的次数(tries)为0的时刻
    if (tries == 0) {
        printf("you lost this game!");
    }
    return 0;
}
