#ifndef FILETYPE_H
#define FILETYPE_H

#include <string>

class FileType {
public:
    static std::string getFileType(const std::string& filePath);  // 文件类型识别函数声明
};

#endif