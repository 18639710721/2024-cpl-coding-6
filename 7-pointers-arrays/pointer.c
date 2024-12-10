//
// Created by 2907568338 on 2024/12/9.
//
#include <stdio.h>

#define PI 3.14

/*
 * 定义指针变量的*和间接寻址运算符的*是不一致的
 *      int *ptr_radius_1 = &radius_1; 这里的*的类型信息的一部分
 *      *ptr_radius_2 这里的*是解引用运算符 和对应内存地址的那个变量是等价的
 *
 *
 *
 *
 *
 */

int main(void) {

    /********** On radius_1 **********/
    // type: int; value: 100; address: &radius_1 (&: address-of)
    int radius_1 = 100;
    printf("radius_1 = %d\n", radius_1);
    printf("&radius_1 = %p\n", &radius_1);

    radius_1 = 200;
    // radius_1 lvalue conversion => rvalue
    double circumference = 2 * PI * radius_1;

    /********** On ptr_radius_1 **********/
    // 变量不过内存地址的别名，指针变量是对内存地址的更高级抽象，
    // 抽象的目的在于屏蔽间接寻址。
    //type int*(感觉这个*像是表明了寻址几次) value: &radius_1
    int *ptr_radius_1 = &radius_1;
    printf("&ptr_radius_1 = %p\n", &ptr_radius_1);
    printf("the value of ptr_radius_1 = %p\n", ptr_radius_1);
    printf("the value of ptr_radius_1 = %p\n", &radius_1);
    printf("the address of radius_1 = %p\n", &radius_1);
    printf("the value of radius_1 = %d\n", *ptr_radius_1);

    /********** On ptr_radius_1 as lvalue and rvalue **********/
    int radius_2 = 300;
    int *ptr_radius_2 = &radius_2;
    // type: int * ptr1 copy l ptr2的地址
    ptr_radius_1 = ptr_radius_2;
    // 验证下指针变量里面保存的值是否一致以及间接寻址访问值是否一致即可
    // 都是一致的 即都指向了pt2所指向的那块内存区域 可以对这块区域进行读写操作
    printf("the value of prt_radius_1 = %p\n", ptr_radius_1);
    printf("the value of ptr_radius_2 = %p\n",ptr_radius_2);
    printf("the value of radius_2 = %d\n", *ptr_radius_1);
    printf("the value of radius_2 = %d\n", *ptr_radius_2);
    printf("the value of radius_2 = %d\n", radius_2);

    /********** On *ptr_radius_1 **********/
    // *ptr_radius_1 behaves like radius_1 间接寻址vs原地址
    // 感觉本质上都是对同一块内存地址进行读写, 只是因为指针变量屏蔽了
    // 对汇编层面间接寻址的抽象
    // 这里*ptr 像是剥开了星号, 把类型转为了int?
    // ptr_radius_1: int *
    *ptr_radius_1 = 400;    // 这里修改的是radius_2的
    printf("radius_1 = %d\n", radius_1);
    printf("radius_2 = %d\n", radius_2);
    printf("radius_2 = %d\n", *ptr_radius_1);  // 因为*ptr和var等级 也可以读值





    return 0;
}