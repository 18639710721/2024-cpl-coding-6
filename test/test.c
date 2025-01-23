//
// Created by 2907568338 on 2024/10/24.
//
#include<stdio.h>
#include <stdlib.h>

int power_self(int exponent, int base);

int multiply_by_addition(int times, int num);

int natural_number_mapping(int times, int successor);

int main() {
    int year;
    printf("Hello World!\n");
    printf("%d", year = 0);

    system("cls");


//    printf("%d\n",power_self(0, 2));
//    printf("%d\n", power_self(1, 2));
//    printf("%d\n", power_self(2, 2));
//    printf("%d\n", power_self(3, 2));
//    printf("%d\n", power_self(4, 2));


//    int base = 2;
//    for(int i = 0; i < 10; i++) {
//        printf("%d\n", power_self(i, 2));
//    }

    // print 1-10 multiply 5
    int num = 5;
    for (int i = 1; i < 11; i++) {

        printf("%d\n", multiply_by_addition(i, num));
    }

    for (int i = 0; i < 10; i++) {
        printf("%d\n", natural_number_mapping(i, 1));
    }
    return 0;


}

int natural_number_mapping(int times, int successor) {
    successor = 1;
    if (times < 0) {
        return 0;
    } else {
        return natural_number_mapping(times - 1, successor) + successor;
    }
}

int multiply_by_addition(int times, int num) {
    if (times == 1) {
        return num;
    } else {
        return multiply_by_addition(times - 1, num) + num;
    }
}

int power_self(int exponent, int base) {
    if (exponent == 0) {
        return 1;
    } else {
        return power_self(exponent - 1, base) * base;
    }
}