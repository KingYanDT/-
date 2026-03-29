#ifndef COMPRESSION_H
#define COMPRESSION_H

#include <string>

class Compression {
public:
    // 压缩文件
    static void compressFile(const std::string& inputFile, const std::string& outputFile);

    // 解压文件
    static void decompressFile(const std::string& inputFile, const std::string& outputFile);
};

#endif