#include <iostream>
#include "FileType.h"  // 引入文件格式识别模块
#include "FileAttributes.h"  // 引入文件属性管理模块
#include "Compression.h"  // 引入压缩解压模块
#include "Encryption.h"  // 引入加密解密模块
#include <string>
#include <algorithm>

void removeQuotes(std::string& str) {
    // 如果字符串两端有双引号，则去除
    if (str.front() == '\"' && str.back() == '\"') {
        str = str.substr(1, str.length() - 2);
    }
}

int main() {
    int choice;
    std::string filePath, outputFile, key;

    while (true) {
        // 打印菜单
        std::cout << "\n请选择操作:\n";
        std::cout << "1. 文件格式识别\n";
        std::cout << "2. 压缩文件\n";
        std::cout << "3. 解压文件\n";
        std::cout << "4. 文件加密\n";
        std::cout << "5. 文件解密\n";
        std::cout << "6. 退出\n";
        std::cout << "请输入选择 (1/2/3/4/5/6): ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // 文件格式识别
            std::cout << "请输入文件路径以识别文件类型 (如 C:\\Users\\...): ";
            std::cin.ignore();  // 忽略掉前一个换行符
            std::getline(std::cin, filePath);
            removeQuotes(filePath);  // 去除路径中的双引号
            std::cout << "文件类型: " << FileType::getFileType(filePath) << std::endl;
            FileAttributes::showFileAttributes(filePath);
            break;
        }
        case 2: {
            // 压缩文件
            std::cout << "请输入要压缩的文件路径 (如 C:\\Users\\...): ";
            std::cin.ignore();  // 忽略掉前一个换行符
            std::getline(std::cin, filePath);
            removeQuotes(filePath);  // 去除路径中的双引号
            std::cout << "请输入压缩输出文件路径 (如 C:\\Users\\...): ";
            std::getline(std::cin, outputFile);
            removeQuotes(outputFile);  // 去除路径中的双引号
            Compression::compressFile(filePath, outputFile);
            break;
        }
        case 3: {
            // 解压文件
            std::cout << "请输入要解压的文件路径 (如 C:\\Users\\...): ";
            std::cin.ignore();  // 忽略掉前一个换行符
            std::getline(std::cin, filePath);
            removeQuotes(filePath);  // 去除路径中的双引号
            std::cout << "请输入解压输出文件路径 (如 C:\\Users\\...): ";
            std::getline(std::cin, outputFile);
            removeQuotes(outputFile);  // 去除路径中的双引号
            Compression::decompressFile(filePath, outputFile);
            break;
        }
        case 4: {
            // 文件加密
            std::cout << "请输入文件路径进行加密 (如 C:\\Users\\...): ";
            std::cin.ignore();  // 忽略掉前一个换行符
            std::getline(std::cin, filePath);
            removeQuotes(filePath);  // 去除路径中的双引号
            std::cout << "请输入加密密钥: ";
            std::cin >> key;
            Encryption::encryptFile(filePath, key);
            std::cout << "文件加密完成!" << std::endl;
            break;
        }
        case 5: {
            // 文件解密
            std::cout << "请输入加密文件路径进行解密 (例如：C:\\Users\\...\\file.enc): ";
            std::cin.ignore();  // 忽略掉前一个换行符
            std::getline(std::cin, filePath);
            removeQuotes(filePath);  // 去除路径中的双引号

            // 检查文件是否是加密文件（例如，检查扩展名是否为 .enc）
            if (filePath.find(".enc") == std::string::npos) {
                std::cout << "警告: 该文件似乎没有经过加密，解密可能会失败！" << std::endl;
                char proceed;
                std::cout << "是否继续进行解密操作？(Y/N): ";
                std::cin >> proceed;
                if (proceed != 'Y' && proceed != 'y') {
                    std::cout << "解密操作已取消！" << std::endl;
                    return 0;
                }
            }

            std::cout << "请输入解密密钥: ";
            std::cin >> key;

            // 让用户输入解密后的文件路径
            std::cout << "请输入解密后的文件路径 (例如：C:\\Users\\...\\12321.txt): ";
            std::cin >> outputFile;

            Encryption::decryptFile(filePath, key, outputFile);
            std::cout << "文件解密完成!" << std::endl;
            break;
        }
        case 6:
            std::cout << "退出程序。\n";
            return 0;
        default:
            std::cout << "无效选择，请重新输入！\n";
            break;
        }
    }

    return 0;
}