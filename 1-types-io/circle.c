//
// Created by 2907568338 on 2024/10/22.
//
#include <stdio.h>

/*
 * identifiers
 * 见命知意 不能已下划线开头
 *
 *  %[flags][width][.[precision]]specifier
 */

int main(void) {
    // declare/define  init
    int radius = 10;

    // assign =
//    radius = 20

    /* expression 2 * 3.14158 * radius
     * An expression is a sequence of operators and their operands,
     * that specifies a computation.
     * has a value
     */

    double circumference = 2 * 3.14158 * radius;
    double area = 3.14159 * radius * radius;

    /* The format string consists of ordinary byte characters (except %), which are copied unchanged into the output stream, and conversion specifications.
     * Each conversion specification has the following format:
     * f format
     * printf函数会依次从左到右读取字符串, 碰到普通字符就按原样输出
     * 另一类%开头的为转换说明 就去查手册根据规则输出
     * %d decimal
     * %f 默认保留小数点6位
     * .2: .是用来做分割用 %f: precision 精度
     */
    printf("radius = %d\ncircumference: %.2f\narea: %.2f", radius, circumference, area);
    return 0;
}