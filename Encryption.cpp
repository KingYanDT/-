#include "Encryption.h"
#include <fstream>

void Encryption::encryptFile(const std::string& filePath, const std::string& key) {
    std::ifstream input(filePath, std::ios::binary);  // 以二进制模式读取输入文件
    std::ofstream output(filePath + ".enc", std::ios::binary);  // 创建加密后的输出文件
    char buffer;
    while (input.get(buffer)) {  // 按字节读取文件
        buffer ^= key[0];  // 简单的按位异或操作进行加密
        output.put(buffer);  // 写入加密后的字节
    }
}

void Encryption::decryptFile(const std::string& filePath, const std::string& key) {
    std::ifstream input(filePath, std::ios::binary);  // 以二进制模式读取加密后的文件
    std::ofstream output(filePath + ".dec", std::ios::binary);  // 创建解密后的输出文件
    char buffer;
    while (input.get(buffer)) {  // 按字节读取文件
        buffer ^= key[0];  // 使用相同的按位异或操作进行解密
        output.put(buffer);  // 写入解密后的字节
    }
}