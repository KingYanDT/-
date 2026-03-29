#include "Compression.h"
#include <iostream>
#include <cstdlib>  // 用于 system() 调用命令

// 压缩文件
void Compression::compressFile(const std::string& inputFile, const std::string& outputFile) {
    // 构建 PowerShell 压缩命令
    std::string command = "powershell Compress-Archive -Path \"" + inputFile + "\" -DestinationPath \"" + outputFile + "\"";

    // 执行压缩命令
    int result = system(command.c_str());

    // 检查是否成功
    if (result == 0) {
        std::cout << "文件压缩完成！" << std::endl;
    }
    else {
        std::cout << "压缩失败！" << std::endl;
    }
}

// 解压文件
void Compression::decompressFile(const std::string& inputFile, const std::string& outputFile) {
    // 构建 PowerShell 解压命令
    std::string command = "powershell Expand-Archive -Path \"" + inputFile + "\" -DestinationPath \"" + outputFile + "\"";

    // 执行解压命令
    int result = system(command.c_str());

    // 检查是否成功
    if (result == 0) {
        std::cout << "文件解压完成！" << std::endl;
    }
    else {
        std::cout << "解压失败！" << std::endl;
    }
}