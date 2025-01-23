//
// Created by 2907568338 on 2024/12/20.
//
#include <stdio.h>
#include <math.h>

double j_invariant_cal_PI(void);

double Carl_Størmer_cal_PI(void);

int main(void) {
    // 3.141592653589793
    printf("%.15f\n", j_invariant_cal_PI());
    printf("%.15f\n", Carl_Størmer_cal_PI());
    return 0;
}

double j_invariant_cal_PI(void) {
    return log(pow(5280, 3) *
               pow((236674 + 30303 * sqrt(61)), 3 )  + 744)/ sqrt(427);
}

double Carl_Størmer_cal_PI(void) {
    return (1.0 * 6 * atan(1.0 * 1 / 8) +
            1.0 * 2 * atan(1.0 * 1 / 57) +
            atan(1.0 * 1 / 239)) * 4;
}