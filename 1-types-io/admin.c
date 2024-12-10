//
// Created by 2907568338 on 2024/10/22.
//

#include <stdio.h>
#include <math.h>
#include <ctype.h>

/*
 * 每组信息占一行
 * 各项信息使用\t间隔
 * 各项信息遵循特定格式要求
 *
 * alt+enter 引入库
 */

/*
 * ctype.h ascii字符表 char
 *      字符在存储底层实际是一个整数
 *      %d 输入整数 %c 输出对应字符
 *
 * C string
 *  A C string is a null-terminated(\0) sequence of characters.
 *  String literal
 *
 *  Conversion Specification
 *  %[flags][width][.[precision]]specifier
 *      %d: decimal int
 *      %f: double
 *      %e %E double(-d.ddde+-dd) 科学计数法
 *      %c char
 *      %s C string
 *      %% %
 */

int main() {
    // 字符串 "" string 把一个一个字符串在一起
    // 这里是字符数组 数组 同样类型的数据排在一起
    char first_name[] = "Dayou";
    char last_name[] = "Luo";

    // char '' 单个字符 字符类型
    /* a char is actually an int   字符在存储底层实际是一个整数
     * a  97
     * A  65
     * 小写转换为大写 直接减32即可 'a' - 'A'
     */
    // 32 magic number
//    char gender = 'm' - 32;
    char gender = 'm' - 'a' + 'A';

    int birth_year = 1954;
    int birth_month = 7;
    int birth_day = 20;

    char weekday[] = "Tuesday";

    int c_score = 50;
    int music_score = 90;
    int medine_score = 80;

    double mean = (c_score + music_score + medine_score) / 3.0;   // 平均数
    double sd = sqrt((pow(c_score - mean, 2) + pow(music_score - mean, 2) + pow(music_score - mean, 2)) / 3.0); // 标准差

    int rank = 10;
    // 这种并置的字符串最后会合成一个字符串
    // %s string
    // %c character
    //.2: .2f .2d 最少打印几位数字
    // .3s 最多输出3个字符
    //.2会根据后面符号的不同选择不同的语义
    // 使用%%对%进行转义
    printf("%s\t%s\t%c\n"
           "%.2d-%.2d-%.4d\t%.3s.\n"
           "%d\t%d\t%d\n"
           "%.1f\t%.1f\t%d%%\n",
           first_name, last_name, toupper(gender),
           birth_month, birth_day, birth_year, weekday,
           c_score, music_score, medine_score,
           mean, sd, rank);


    return 0;
}
