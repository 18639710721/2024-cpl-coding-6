#include <stdio.h>


void swapVariable(int a, int b);
void swapVariablePointer(int *a, int *b);
void swapVariableBitWise(int *a, int *b);

int main(void) {
    // TODO: swap the values of two variables
    int a = 5;
    int b = 6;
    swapVariable(a, b);
    // 函数是在栈上并没有修改外部空间的数据,
    printf("the value of a is: %d\n", a);
    printf("the value of b is: %d\n", b);

    // 使用指针成功修改了数据
    swapVariablePointer(&a, &b);
    printf("the value of a is: %d\n", a);
    printf("the value of b is: %d\n", b);

    // 重置一下初始状态
    a = 5;
    b = 6;
    // 使用异或修改数据
    swapVariableBitWise(&a, &b);
    printf("the value of a is: %d\n", a);
    printf("the value of b is: %d\n", b);

    return 0;
}

void swapVariable(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("the value of a is: %d\n", a);
    printf("the value of b is: %d\n", b);
}

void swapVariablePointer(int *a, int *b) {
    int temp  = *a;
    *a = *b;
    *b = temp;
}


void swapVariableBitWise(int *a, int *b) {
    // 异或运算同时保持了a和b的信息 可以还原
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}