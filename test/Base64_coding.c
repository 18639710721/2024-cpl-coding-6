//
// Created by 2907568338 on 2025/1/9.
//

/*
 * Base64使用了64个字符 将二进制数据转换为可打印字符
 *  1.构建base64
 **/

// 函数原型
char *base64_encode(char* input, int input_len);

// Base64 可打印字符集
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int main(void) {



    return 0;
}

char *base64_encode( char* input, int input_len) {
    // 1. 处理padding
    int padding = 0;
    if (input_len % 3 != 0) {
        padding = 3 - (input_len % 3);
        for (int i = 0; i < padding; i++) {
            input[input_len + i] = 0;    // 用0填充不足的字节
        }

    }
}