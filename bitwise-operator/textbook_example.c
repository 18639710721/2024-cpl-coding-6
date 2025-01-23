//
// Created by 2907568338 on 2025/1/9.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/*
 * 1.了解大小端的概念 计算机默认是小端
 * 2.了解位移运算符号 以及&1的特点
 * 3. debug在内存中观察是大端还是小端存储才知道为什么位运算的代码那样写
 * 移位运算遵循人类阅读数字的习惯 和计算机的实际存储无关
 *
 * 这里使用位运算感觉int32个比特很多情况下都浪费空间了，可以定义更小的数据类型避免浪费
 *
 */

/* windows 控制台支持显示 utf8 编码的中文字符 */
/*输入中文乱码的解决方案 https://zhuanlan.zhihu.com/p/531460693*/
void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

// 按位与和按位或
void checkEndianess(void);
void printBinary(int num);
int maskTest(int num);
void filterRgbColors(unsigned int num);
void simulateLightStatus(void);

// 取反操作
// 2.取反操作是可逆映射 不会丢失信息可以还原
// 3.负数的补码等于原码取反+1
// 实质为模2的n次方剩余类 可以通过单位元定义

// 验证一个正数所对应的负数的补码等于正数的反码+1
// 1.利用0-x(这个正数获得其补码表示)
// 2.重复正数取反加一操作即可
uint8_t bitwiseNotTest(uint8_t num);
int verify_complement(int positive_num);

// 左移和右移位运算符
void unsignedLeftShiftColor(void);

// 异或运算 逆元是本身 单位元是0 本质上是模2(2阶)加法群
uint8_t dataBackupUsingXOR(uint8_t original_data);
void simulateGameData(void);
void XORPropertyTest(void );
// 异或实现简单的加密操作(对称加密)
void xorEncrypt(char *plaintext, const char *key);
void xorDecrypt(char *ciphertext, const char *key);


int main(void) {
    windows_cmd_support_utf8();
    unsigned short i, j;
    i = 13;
    j = i << 2;
    j = i >> 2;
    printf("%d\n", j);
    checkEndianess();
    int num = 1;
    printBinary(1);

    // 对170进行掩码运算
    // 10101010
    // 11110000
    // 10100000  result
    int masked_number = maskTest(170);
    printf("%d\n", masked_number);
    printBinary(masked_number);

    filterRgbColors(0xFFFFFF);
    printf("\n");
    simulateLightStatus();

    uint8_t test_num = 0xFF;
    test_num = bitwiseNotTest(test_num);
    printBinary(test_num);
    // A = 取反 B 当且仅当 B = 取反A 可逆映射 具有还原性
    printf("%d\n", 0xFF == bitwiseNotTest(test_num));

    printBinary(-1);
    printBinary(-2);
    printf("%d\n", 0 - 2);
    printf("%s\n", verify_complement(22)?"true":"false");
    printf("%s\n", verify_complement(33)?"true":"false");

    unsignedLeftShiftColor();

    uint8_t backup_data = dataBackupUsingXOR(0b01010101);
    printBinary(backup_data);
    printf("%s\n", dataBackupUsingXOR(backup_data) == 0b01010101 ?"true":"false");
    simulateGameData();
    XORPropertyTest();

    // 使用异或实现函数加解密
    char plaintext[] = "Hello, World!";
    const char key[] = "secret";
    printf("明文: %s\n", plaintext);
    xorEncrypt(plaintext, key);
    printf("密文: %s\n", plaintext);
    xorDecrypt(plaintext, key);
    printf("解密后的文本: %s\n", plaintext);

    return 0;
}

void checkEndianess(void) {
//    大端（Big-Endian）
//    概念：也叫大端序或大字节序。数据的高位字节存于低地址，低位字节存于高地址，就像按从左到右（高位在前）的顺序存储。
//    示例：对于 32 位整数0x12345678，在大端模式下，内存中从低地址到高地址的存储顺序是0x12、0x34、0x56、0x78。就像按人们正常读写数字的习惯，先写高位数字。常用于网络协议、一些文件格式等，符合人类正常思维习惯，数据的高位部分先被看到和处理。
//    小端（Little-Endian）
//    概念：也称小端序或小字节序。与大端相反，数据的低位字节存于低地址，高位字节存于高地址，如同从右到左（低位在前）存储。
//    示例：对于0x12345678，在小端模式下，内存存储顺序是0x78、0x56、0x34、0x12。这种方式更利于计算机处理，因为 CPU 按字节读取内存时从小地址开始，先读取到数据的低位部分，无需额外转换操作，很多微处理器和微控制器默认采用小端模式。
//    实际应用中，需注意大端和小端的差异，如在网络编程中，不同主机字节序可能不同，要进行字节序转换以确保数据正确传输和处理；在文件读写、跨平台开发等场景也需考虑，可通过特定函数或宏进行字节序转换，保证数据在不同环境下的一致性和正确性。

//    C 语言本身既支持大端也支持小端，具体使用哪种字节序取决于所运行的硬件平台。
//    小端平台常见：像 x86、ARM 等多数通用处理器平台默认采用小端序。在这些平台上，
//          C 语言程序按小端方式存储和处理多字节数据。如在 32 位 x86 平台上定义int num = 0x12345678，
//          内存中按0x78、0x56、0x34、0x12顺序存储。
//    大端平台也存在：一些特定的硬件架构如 PowerPC 在某些模式下是大端序。在大端序的 PowerPC 平台上，
//          上述int num = 0x12345678，内存中存储顺序是0x12、0x34、0x56、0x78。实际编程中，
//          若要编写跨平台且对字节序敏感的 C 程序，可通过代码检测或转换字节序。比如可利用联合体union的特性检测当前平台字节序，
//           也可使用htonl、ntohl等函数在网络字节序（大端）和主机字节序间转换。
    int arr[] = {0x12345678};
    printf("An int is %zu bits.\n", sizeof(arr[0]) * 8);
    printf("%d\n", arr[0]);
    char *p = (char *) &arr[0];
    if (*p == 0x12) {
        printf("大端序\n");
    } else if (*p == 0x78) {
        printf("小端序\n");
    } else {
        printf("未知字节序\n");
    }
}

void printBinary(int num) {
    int bit = 0;
    int size = sizeof(int) * 8;
    for (int i = size - 1; i >= 0; i--) {
        int shifted = num >> i;   // 从0开始右移位
        bit = shifted & 1;
        printf("%d",bit);
    }
    printf("\n");

}

int maskTest(int num) {
    /** 利用位运算进行掩码操作（Mask operation）
     *  a & 1 = a(布尔代数乘法单位元定义)
     *  a & 0 = 0(Domination Law)
     *  对于二进制数据部分与1可以保留原部信息，因为是一个恒等变换
     *  与0则因为Domination Law 丢失了所有信息
     */

    // 对170进行掩码运算
    // 10101010
    // 11110000
    // 10100000  result
    printBinary(num);
    printBinary(0xF0);
    return num & 0xF0;
}

void filterRgbColors(unsigned int num) {
    /* 牛顿当年通过三棱镜把白色光进行分解
     * 白色 RGB(255, 255, 255)
     * 黑色 RGB(0, 0, 0)
     * 这个颜色空间可以看成红绿蓝三个基向量的线性组合
     * 该函数利用与运算掩码模拟过滤出纯红绿蓝颜色的图片
     * 0xRRGGBB
     */
    // 0xFFFFFF  一个R的范围是0到255 用八个bits来表示
    // 16进制可以把二进制四个bits一分组 所有可以用两个16进制数字来表示
    unsigned int pure_R = num & 0xFF0000;    //  只保留红色
    unsigned int pure_G = num & 0x00FF00;    // 只保留绿色
    unsigned int pure_B = num & 0x0000FF;    // 只保留蓝色
    printBinary(pure_R);  // 这里类型转换懒得搞了，大的向小的转换的确很多问题
    printBinary(pure_G);
    printBinary(pure_B);
}

void simulateLightStatus(void) {
    /* 测试或运算如何改变灯泡状态
     * a | 0 = a (布尔代数加法单位元)
     * a | 1 = 1 (Domination Laws)
     * 对于二进制数据部分或0可以保留原本数据, 因为是一个恒等变换
     * 或1则因为Domination Law 全部都强制修改成立1
     *
     * 需求 将楼上灯泡全部开启，楼下灯泡状态保持不变
     *     楼上灯泡状态为0100 楼下灯泡状态为1111
     *     每一个bits都灯泡的状态 假设0表示灯泡关闭 1表示灯泡开启
     *
     *     楼上可以或1全部强制为开启状态，楼下或0恒等变换保持不变即可
     */

    uint8_t light_default_status = 0b01001111;
    uint8_t restart_light_status = light_default_status | 0b11110000;
    printBinary(restart_light_status);
}

// 测试取反操作
uint8_t bitwiseNotTest(uint8_t num) {
    return ~num;
}

int verify_complement(int positive_num) {
    // 验证一个正数所对应的负数的补码等于正数的反码+1
    // 1.利用0-x(这个正数获得其补码表示)
    // 2.重复正数取反加一操作即可
    int negative_number = 0 - positive_num;
    return negative_number == ((~positive_num) + 1);
}

void unsignedLeftShiftColor(void) {
    // 用移位运算符过滤颜色
    unsigned int color = 0x2CDEF2;
    unsigned char red, green, blue;
    red = color >> 16;
    green = color & 0xFF00;
    green = color >> 8;
    blue = color & 0xFF;
    printf("Red:%hhx Green:%hhx Blue:%hhx\n", red, green, blue);
}

// 利用异或存在逆运算就是其本身 实现数据备份功能
// 即对ab数据进行异或等到c 知道其中任意两个都可得到原数据
uint8_t dataBackupUsingXOR(uint8_t original_data) {
    uint8_t key = 0b11110000;
    uint8_t backup_data = original_data ^ key;
    return backup_data;
}

// 修改游戏中宝石的数据 可以通过备份数据还原
void simulateGameData(void) {
    unsigned diamonds = 2500;
    unsigned vipExp = 2200;

    unsigned v = diamonds ^ vipExp;

    // 破坏过程
    diamonds = 1200;

    diamonds = vipExp ^ v;
    printf("%d\n", diamonds);
}

void XORPropertyTest(void) {
    uint8_t test_data = 0b00001111;

    // 这里直接使用位运算在c语言中会被强制提升到int类型
    // 要么用(uint8_t)强制转换，要么用掩码把前面的都干掉 &0xFF
    printf("%s\n", ((uint8_t)(test_data ^ 0b11111111) == (uint8_t)(~test_data)) ?"true":"false");

    printf("%s\n",((uint8_t)(test_data ^ (~test_data)) == 0b11111111 )?"true":"false");
    // 逆元
    printf("%s\n",(test_data ^ test_data) == 0 ?"true":"false");
    // 单位元
    printf("%s\n", (test_data ^ 0) == test_data ?"true":"false");
}

void xorEncrypt(char *plaintext, const char *key) {
    unsigned int key_length = strlen(key);
    unsigned int key_index = 0;
    for(int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] = plaintext[i] ^ key[key_index];
        // 如果取到密匙边界情况 key_length - 1 会直接+1从零开始循环
        // 其他情况都会正常加一 因为大部分情况密匙长度都比较小 使用模运算反复使用
        key_index = (key_index + 1) % key_length;
    }
}
void xorDecrypt(char *ciphertext, const char *key) {
    // 利用异或加密的可逆性,解密过程和加密过程相同，直接调用加密函数
    xorEncrypt(ciphertext, key);
}