//
// Created by 2907568338 on 2024/11/13.
//

#include <stdio.h>

#define LEN 20
int numbers[LEN] = {10, 20, 30, 50 , 70, 89};

int main() {
    // window下使用不了这个信号 貌似只能用ctrl+c停止
    /*
     * Input the array
     *
     * Note: fails to run this program in "Run" (Ctrl + D)
     * See: https://youtrack.jetbrains.com/issue/CPP-5704
     * Use "Terminal" instead.
     *
     * TODO: CLion; Terminal
     * Linux: Ctrl + D (works now; in the new line, or Ctrl + D twice)
     *   See https://stackoverflow.com/a/21365313/1833118 (send and clear the buffer)
     * Windows: Ctrl + Z (does not work on my platform)
     * TODO: Input&Output redirection
     *   See https://stackoverflow.com/a/11788475/1833118
     */
//    int len = -1;
    // stream
    // (1) input failure: EOF (-1)   数据读完了再读取的情况 EOF是个信号表示终止
    // (2) match failure: assigned items >= 0  遇见字符不匹配会直接终结
    // ++len 先加加 再赋值
//    while (scanf("%d", &numbers[++len]) != EOF);

//    for (int i = 0; i < 5; i++) {
//        scanf("%d", &numbers[i]);
//    }
    // sizeof numbers / sizeof[numbers[0]] 数组长度
    printf("%llu\n", sizeof numbers / sizeof(numbers[0]));

    // TODO: selection sort
    // n-2 趟即可排序完成
    for(int i = 0; i <= LEN - 2; i++) {
        // find the minimum of numbers[i, len-1]
        // 在这个区间搜索,找到最小的再和第i个位置的进行交换
        int min = numbers[i];
        int min_index = i;
        for(int j = i; j <= LEN - 1; j++) {
            if(numbers[j] < min) {
                min = numbers[j];
                min_index = j;
            }
        }
        // 循环结束后 swap(A[i], A[min]) 交换第i个和最小的
        // 使得第i次循环前i-1个元素都是有序的
        // 交换两个变量就像倒水一样，需要引入第三个杯子
        int temp = numbers[i];
        numbers[i] = numbers[min_index];
        numbers[min_index] = temp;

    }

    for (int i = 0; i < LEN; i++){
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
