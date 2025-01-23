//
// Created by 2907568338 on 2024/12/20.
//
#include <stdio.h>
#include <math.h>

#define MOLNUM 10007

int calFactorial(int num);

int factorialSumMod10007(int n);

int factorialSumMod10007GammaVersion(int n);

int main(void) {
    int num = 0;
    scanf("%d", &num);

    printf("%d\n", factorialSumMod10007GammaVersion(num));
    return 0;
}

int calFactorial(int num) {
    if (num == 0) {
        return 1;
    } else {
        return calFactorial(num - 1) * num;
    }
}

int factorialSumMod10007(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += calFactorial(i) % MOLNUM;
        sum = sum % MOLNUM;
    }

    return sum % MOLNUM;
}

int factorialSumMod10007GammaVersion(int n) {
    int sum = 0;
    // gamma(n+1) = factorial(n)
    for(int i = 1; i <= n; i++) {
        sum += tgamma(i + 1) %  MOLNUM;
        sum +
    }

    return sum % MOLNUM;
}