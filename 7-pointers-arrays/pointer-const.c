//
// Created by 2907568338 on 2024/12/9.
//
#include <stdio.h>

int main(void) {
    // 指针就是地址？WTF
    // 那int *类型表明 object的content是一个指向int的地址

    // 地址是有不同类型的
    // 因为地址就是指针 所以指针是有不同类型的
    int v = 100;
    int *pv =  &v;
    // 这里类型转换多少是有问题的
    pv = &pv;
    printf("the address of v = %p\n", &v);
    printf("the address of pv = %p\n", *pv);


    return 0;
}