//
// Created by 2907568338 on 2024/12/15.
//
#include <stdio.h>
#include <string.h>


// 1. Simple Hash Function for Strings
unsigned int simple_hash(const char *str) {
    unsigned int hash = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        hash += str[i];
    }

    return hash;
}

// 2. Improve Uniformity: Polynomial Hash
unsigned int polynomial_hash(const char *str, int prime) {
    unsigned int hash = 0;
    unsigned int multiplier = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        // 多项式的权值默认是从0次方开始 所以为1
        hash += str[i] * multiplier;
        // 更新权值  相乘即为指数
        multiplier *= prime;
    }

    return hash;
}

/*
 * 3. Modular Hash Function
 * To limit the hash values to a specific range (useful for hash tables):
 */
unsigned int modular_hash(const char *str, int table_size) {
    unsigned int hash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash = (hash * 31 + str[i]) % table_size;
    }
    return hash;
}

int main(void) {
    const char *key = "hello";
    printf("Hash of '%s': %u\n", key, simple_hash(key));
    printf("Hash of '%s': %u\n", key, polynomial_hash(key, 31));
    printf("Hash of '%s': %u\n", key, modular_hash(key, 31));



}
