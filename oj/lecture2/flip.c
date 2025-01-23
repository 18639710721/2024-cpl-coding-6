//
// Created by 2907568338 on 2024/12/22.
//

#include <stdio.h>
#include <math.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i * i <= n; i++) {
        printf("%d ", i * i);
    }
    printf("\n");

    return 0;
}
