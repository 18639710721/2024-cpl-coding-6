//
// Created by 2907568338 on 2024/11/5.
//
#include <stdio.h>
#include <stdbool.h>

/* pass by value   今日份最重要的内容
 * 代码认知复杂度 即别人阅读代码的难易程度
 *
 * C语言命名规范(华为和谷歌)
 *
 * 函数
 *    隐藏具体的实现细节
 *    函数返回值 函数名(类型 参数名) {
 *      返回语句
 *    }
 *    () 函数调用运算符 构成表达式
 *    调用函数前要先定义
 *
 *    scope 作用域
 *        函数原型作用域
 *        块作用域 {}
 *          这{}这个区域里面可以访问
 *          参数列表声明的变量也是块作用域
 *
 *    formal parameter(形参) 参数列表里定义的
 *    int year: actual argument(实参) 实际传过来的参数
 *    函数调用时参数传递的过程
 *         从形参到实参的赋值过程
 *         拿到了实参值的一份拷贝
 *
 *
 */


/*
1 函数主要是隐藏实现细节
  () 函数调用运算符 构成表达式
  表达式是有值的

  函数声明
  函数定义

  作用域 scope
  {} blcok
  这{}这个区域里面可以访问
  参数列表声明的变量也是块作用域

  函数原型作用域
  形参
  实参

  形参 = 实参 一个拷贝的动作(赋值)

 */

// function declaration 函数声明(原型) 带分号的
// function prototype scope 函数原型作用域
bool IsLeapYear(int year); // formal parameter(形参)


int main(void) {
    // block scope(块作用域) {}内部都可以访问到
    int year = 0;

    scanf("%d", &year);

    // (): function call operator
    // IsLeapYear(year) 函数名和运算的参数构成一个有值的表达式
    // int year: actual argument(实参) 实际传过来的参数
    bool leap = IsLeapYear(year);
    if (leap == false) {
        printf("%d is common year", year);
    } else {
        printf("%d is leap year", year);
    }
    return 0;
}

// 函数签名
// 带{}是函数定义 function definition
// block scope 参数列表定义的year作用域{}
bool IsLeapYear(int year) {
    bool leap = 0;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ) {
        leap = 1;
    }
    return leap;
}