//
// Created by 2907568338 on 2025/1/3.
//
#include <stdio.h>
#include <stdlib.h>

int *incrementalDifSeqIter(int n, int *result);
int  incrementalDifSeqRecur(int n);


int main(void) {
    int n = 0;
    scanf("%d", &n);
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*) malloc(n * sizeof (int));
    int *result = incrementalDifSeqIter(n, arr1);
    for(int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");

    for(int i = 0; i < n; i++) {
        arr2[i] = incrementalDifSeqRecur(i+1);
        printf("%d ", arr2[i]);
    }

    free(arr1);
    free(arr2);



    return 0;
}

int *incrementalDifSeqIter(int n, int *result) {
    for(int i = 0; i < n; i++) {
        result[i] = 1 + (i * (i + 1)) / 2;
    }

    return result;
}

int incrementalDifSeqRecur(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return incrementalDifSeqRecur(n - 1) + n - 1;
    }

}
