#ifndef FILETYPE_H
#define FILETYPE_H

#include <string>

class FileType {
public:
    static std::string getFileType(const std::string& filePath);  // 声明文件格式识别函数
};

#endif