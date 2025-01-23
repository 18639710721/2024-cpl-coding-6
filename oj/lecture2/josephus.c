//
// Created by 2907568338 on 2024/12/22.
//

#include <stdio.h>

// 约瑟夫问题递推法
int josephus(int n, int k) {
    int survivor = 0;  // f(1, k) = 0，最后一个人的索引为 0
    for (int i = 2; i <= n; i++) {
        survivor = (survivor + k) % i;  // 递推公式
    }
    return survivor + 1;  // 将结果转换为实际编号（从 1 开始）
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", josephus(n, k));
    return 0;
}