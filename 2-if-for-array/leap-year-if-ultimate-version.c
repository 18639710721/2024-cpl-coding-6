//
// Created by 2907568338 on 2024/11/5.
//
#include <stdio.h>

/*
 * TODO: leap year or not (logical expressions)
 * 找到某年是闰年的充分必要条件
 *      1.it is divisible by 4 but not by 100
 *      2.except that years divisible by 400 are leap years
 *      四年一闰，百年不闰 or 四百年再闰
 * 优化
 *      1.根据为真的条件，将if-else优化为逻辑表达式 感觉有点像
 *      通过真值表确定布尔表达式的过程
 *      2.与或非的定义以及短路求值
 *      3.C语言中0为假,非0为真，所以可以写成!variable
 */

void leap_year_cascade_version() {
    int year = 0;
    int leap = 0;

    scanf("%d", &year);


    // 找到判断闰年都为真的条件
    if (year % 4 != 0) {
        leap = 0;
    } else if (year % 100 != 0) {
        leap = 1;    // year % 4 == 0 and year % 100 != 0
    } else if (year % 400 != 0) {
        leap = 0;
    } else {        // year % 4 == 0 and year % 100 == 0 and year % 400 == 0
        leap = 1;
    }


    if (leap == 0) {
        printf("%d is common year", year);
    } else {
        printf("%d is leap year", year);

    }

}

void leap_year_ultimate_version() {
    int year = 0;
    int leap = 0;

    scanf("%d", &year);
    // TODO: leap year or not (logical expressions)
    // &&: and 当且仅当两者都为真才为真 否则为假
    // ||: or  当且仅当两者都为假时为假 否则为真
    // !: not  !A is ture <=> A is false
    // short-circuit(短路求值)
    // A && B: if A is false, B is passed
    // A || B: if A is True, B is passed
    // p * 0 = 0   p + 1 = 1 Domination Laws

    // 0: false; not 0: True


    // 如何表达式为1成立 赋值1 如何不成立为0 赋值0
    // 这是一致的 所以可以优化成更简单的表达式
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        leap = 1;
    }

//    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;


    // 0: false; not 0: True
    if(5) {

    }

    // if (!leap)
    // !leap is true <=> lear is false <=> leap == 0

    if (leap == 0) {
        printf("%d is common year", year);
    } else {
        printf("%d is leap year", year);
    }
}

void leap_year_ultimate_inverse_version(){
    int year = 0;
    int leap = 0;

    scanf("%d", &year);
    // TODO: leap year or not (logical expressions)
    // TODO: 根据上面的logical expression 写一个反转条件的情况
    // &&: and 当且仅当两者都为真才为真 否则为假
    // ||: or  当且仅当两者都为假时为假 否则为真
    // !: not  !A is ture <=> A is false

    if ((year % 4 != 0 || year % 100 == 0) && (year % 400 != 0) ) {
        leap = 0;
    } else {
        leap = 1;
    }

    if (leap == 0) {
        printf("%d is common year", year);
    } else {
        printf("%d is leap year", year);
    }

}

int main(void) {
    leap_year_ultimate_version();
//    leap_year_ultimate_inverse_version();
    return 0;
}