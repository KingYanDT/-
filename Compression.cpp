#include "Compression.h"
#include <fstream>

void Compression::compressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile, std::ios::binary);  // 以二进制方式读取输入文件
    std::ofstream output(outputFile, std::ios::binary);  // 以二进制方式写入输出文件
    output << input.rdbuf();  // 将输入文件内容复制到输出文件，模拟压缩
}

void Compression::decompressFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream input(inputFile, std::ios::binary);  // 以二进制方式读取输入文件
    std::ofstream output(outputFile, std::ios::binary);  // 以二进制方式写入输出文件
    output << input.rdbuf();  // 将输入文件内容复制到输出文件，模拟解压
}