#include "FileType.h"
#include <fstream>

std::string FileType::getFileType(const std::string& filePath) {
    std::ifstream file(filePath, std::ios::binary);  // 打开文件，以二进制模式读取
    if (!file) {
        return "无法打开文件";  // 如果文件无法打开，返回错误信息
    }

    char buffer[4];  // 缓冲区用于存储文件头的前4个字节
    file.read(buffer, 4);  // 读取文件的前4个字节
    if (file.gcount() < 4) {
        return "文件过小无法识别";  // 如果文件小于4个字节，无法识别
    }

    // 判断文件类型，根据文件头信息
    if (buffer[0] == 0x50 && buffer[1] == 0x4B) {  // ZIP文件的标识为 "PK"
        return "ZIP压缩文件";
    }

    return "未知文件类型";  // 如果无法识别文件类型，返回 "未知文件类型"
}