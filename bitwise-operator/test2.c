#include <stdio.h>
#include <string.h>

// XOR加密函数
void xorEncrypt(char *plaintext, const char *key, size_t length) {
    unsigned int key_length = strlen(key);
    unsigned int key_index = 0;

    for (size_t i = 0; i < length; i++) {
        plaintext[i] = plaintext[i] ^ key[key_index];
        key_index = (key_index + 1) % key_length;
    }
}

// XOR解密函数
void xorDecrypt(char *ciphertext, const char *key, size_t length) {
    // 解密过程与加密过程相同
    xorEncrypt(ciphertext, key, length);
}

int main() {
    char plaintext[] = "Hello, World!";
    const char key[] = "secret";

    // 记录明文长度
    size_t length = strlen(plaintext);

    printf("明文: %s\n", plaintext);

    // 加密
    xorEncrypt(plaintext, key, length);
    printf("密文: ");
    for (size_t i = 0; i < length; i++) {
        printf("%02X ", (unsigned char)plaintext[i]); // 打印密文的十六进制表示
    }
    printf("\n");

    // 解密
    xorDecrypt(plaintext, key, length);
    printf("解密后的文本: %s\n", plaintext);

    return 0;
}
