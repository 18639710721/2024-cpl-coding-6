//
// Created by 2907568338 on 2024/12/22.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 平衡三进制转换为十进制
int balanced_ternary_to_decimal(const char *s) {
    int len = strlen(s);
    int result = 0;
    int power = 1;  // 3^0 = 1

    // 从最低位到最高位遍历
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == '0') {
            // 0 不影响结果，跳过
        } else if (s[i] == '1') {
            result += power;
        } else if (s[i] == 'Z') {
            result -= power;
        } else {
            return -999999;  // 非法字符返回错误标志
        }
        power *= 3;  // 更新权重 3^i
    }
    return result;
}

int main(void) {
    int n;
    scanf("%d", &n);  // 读取转换个数

    char buffer[20];  // 最多 15 位字符，留足空间
    for (int i = 0; i < n; i++) {
        scanf("%s", buffer);  // 读取每个平衡三进制字符串
        int result = balanced_ternary_to_decimal(buffer);
        if (result == -999999) {
            printf("Radix Error\n");
        } else {
            printf("%d\n", result);
        }
    }
    return 0;
}
