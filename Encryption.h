#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>

class Encryption {
public:
    static void encryptFile(const std::string& filePath, const std::string& key);  // 加密文件
    static void decryptFile(const std::string& filePath, const std::string& key);  // 解密文件
};

#endif