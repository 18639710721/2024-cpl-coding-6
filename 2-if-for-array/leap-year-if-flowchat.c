//
// Created by 2907568338 on 2024/11/4.
//
#include <stdio.h>

/*
 * 根据Flowchart实现判断闰年(leap  year or common year)
 *
 * boolean variable(0/1 false/true)
 *      暂时用整型来表示
 *
 * == && =
 *      == comparison operator
 *      = assignment operator
 *
 * arrow code
 *      嵌套的if-else显得头重脚轻
 */

int main(void) {
    // boolean variable(0/1 false/true)
    // 暂时用整型来表示
    int year = 0;
    int leap = 0;   // default is not leap year

    scanf("%d", &year);


    // year % == 0 等价于 4 | year comparison 比较运算符
    // == equal or not
    // =  assignment operator
    // year % 4 is not a lvalue(left value)
    // 最常见的左值就是变量
    // assignment expression 的值是这个变量的值
    // > (arrow code) 头重脚轻

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if(year % 400 == 0) {
                year = 1;
            } else {
                year = 0;
            }
        } {
            year = 0;
        }
    } else {
        year = 0;
    }

    if(leap == 0) {
        printf("%d is common year", year);

    } else {
        printf("%d is leap year", year);
    }


    return 0;
}