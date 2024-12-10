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
 *
 *  未定义行为
 *      打印没有初始化的变量会产生乱码
 */

/* scanf()
 *     终端用回车显示scanf已经结束了
 *     1.普通字符
 *     2.转换说明
 *     3.空白符
 *     %s和%d前面会自动忽略前导空白符(换行 空格 制表符 常见)
 *     %s会从左到右开始读取, 自动忽略前导的空白符,识别到连续的字符串，
 *     直到读到空白字符,表示匹配到了这个字符串，有点字符串算法的感觉
 *     (不知道是不是正则表达式),匹配到之后根据变量地址存储到这个变量里面
 *
 *     空白符感觉有点像贪婪匹配1个或任意多个空白符
 *
 *      %c和%s不同 会匹配空白字符
 *
 *      &gender要加取址符, 而字符数组不用加的原因是
 *      因为数组名表示的是地址。
 *      为啥要取地址 因为要拿到变量的地址存入数据
 *
 *      没有按照格式-匹配失败则自动退出
 *
 *      float使用scanf要用%lf
 *
 *      本质是字符串匹配算法
 *
 *      格式化串和参数不匹配的话又是一个未定义行为
 *
 *      * 匹配到并不赋值给变量
 *
 *      没有申请空间却写入东西
 *      %9s 排除末尾的0 限制匹配9个字符
 *
 *      %[*][width][specifier]
 *          *: assignment-suppressing
 *      %d: skip white-spaces; match a decimal int
 *      %lf: skip white-spaces; match a double
 *      %c: match a char(dot NOT skip white-spaces)
 *      %% match a %
 *
 */

/*
 * C string is a null-terminated(\0) sequence of characters.
 * String literal: 'T','a','y','u','\0'
 *      "Tayu" 其实是五个字符
 * conversion Specification
 * %[flags][width][.[precision]]specifier
 *      %d decimal int
 *      %f double
 *      %e %E double(-d.ddd e +_ dd)
 *      %c char
 *      %s C string
 *      %% %
 */

int main() {
    char first_name_t[5] = "Tayu";
    // 字符串 "" string 把一个一个字符串在一起
    // 这里是字符数组 数组 同样类型的数据排在一起
    char first_name[10];
    char last_name[10];

    // char '' 单个字符 字符类型
    /* a char is actually an int   字符在存储底层实际是一个整数
     * a  97
     * A  65
     * 小写转换为大写 直接减32即可 'a' - 'A'
     */
    // 32 magic number
//    char gender = 'm' - 32;
    char gender = 'm' - 'a' + 'A';

    int birth_year;
    int birth_month;
    int birth_day;

    char weekday[] = "Tuesday";

    int c_score = 50;
    int music_score = 90;
    int medine_score = 80;

    double mean = (c_score + music_score + medine_score) / 3.0;   // 平均数
    double sd = sqrt((pow(c_score - mean, 2) + pow(music_score - mean, 2) + pow(music_score - mean, 2)) / 3.0); // 标准差

    int rank = 10;


//    scanf("%s%s %c%d-%d-%d %s %d%d%d %lf%lf%d",
//          first_name, last_name, &gender,
//          &birth_month, &birth_day, &birth_year, weekday,
//          &c_score, &music_score, &medine_score,
//          &mean, &sd, &rank);

    scanf("%9s%9s %c%d-%d-%d %s %d%d%d %*lf%*lf%d",
          first_name, last_name, &gender,
          &birth_month, &birth_day, &birth_year, weekday,
          &c_score, &music_score, &medine_score,
           &rank);



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


