#include <iostream>
#include "FileType.h"  // 引入文件格式识别模块
#include "FileAttributes.h"  // 引入文件属性管理模块
#include "Compression.h"  // 引入压缩解压模块
#include "Encryption.h"  // 引入加密解密模块

int main() {
    std::string filePath;

    // 文件格式识别
    std::cout << "请输入文件路径以识别文件类型: ";
    std::cin >> filePath;
    std::cout << "文件类型: " << FileType::getFileType(filePath) << std::endl;

    // 文件属性管理
    FileAttributes::showFileAttributes(filePath);

    // 压缩和解压
    std::string outputFile;
    std::cout << "请输入要压缩的文件路径: ";
    std::cin >> filePath;
    std::cout << "请输入压缩输出文件路径: ";
    std::cin >> outputFile;
    Compression::compressFile(filePath, outputFile);
    std::cout << "文件压缩完成!" << std::endl;

    // 解压文件
    std::cout << "请输入要解压的文件路径: ";
    std::cin >> filePath;
    std::cout << "请输入解压输出文件路径: ";
    std::cin >> outputFile;
    Compression::decompressFile(filePath, outputFile);
    std::cout << "文件解压完成!" << std::endl;

    // 加密和解密
    std::string key;
    std::cout << "请输入加密/解密密钥: ";
    std::cin >> key;
    Encryption::encryptFile(filePath, key);
    std::cout << "文件加密完成!" << std::endl;
    Encryption::decryptFile(filePath + ".enc", key);
    std::cout << "文件解密完成!" << std::endl;

    return 0;
}