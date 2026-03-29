#include "FileType.h"
#include <fstream>
#include <algorithm>

// 判断文件类型
std::string FileType::getFileType(const std::string& filePath) {
    // 转为小写，统一处理文件扩展名
    std::string lowerPath = filePath;
    std::transform(lowerPath.begin(), lowerPath.end(), lowerPath.begin(), ::tolower);

    // 判断文件扩展名
    if (lowerPath.find(".txt") != std::string::npos) {
        return "文本文件";
    }
    else if (lowerPath.find(".jpg") != std::string::npos || lowerPath.find(".jpeg") != std::string::npos) {
        return "JPEG 图片";
    }
    else if (lowerPath.find(".png") != std::string::npos) {
        return "PNG 图片";
    }
    else if (lowerPath.find(".gif") != std::string::npos) {
        return "GIF 图片";
    }
    else if (lowerPath.find(".zip") != std::string::npos) {
        return "ZIP 压缩文件";
    }
    else if (lowerPath.find(".rar") != std::string::npos) {
        return "RAR 压缩文件";
    }
    else if (lowerPath.find(".mp4") != std::string::npos) {
        return "MP4 视频";
    }
    else if (lowerPath.find(".avi") != std::string::npos) {
        return "AVI 视频";
    }
    else if (lowerPath.find(".pdf") != std::string::npos) {
        return "PDF 文件";
    }
    else if (lowerPath.find(".doc") != std::string::npos || lowerPath.find(".docx") != std::string::npos) {
        return "Word 文档";
    }
    else if (lowerPath.find(".xls") != std::string::npos || lowerPath.find(".xlsx") != std::string::npos) {
        return "Excel 文件";
    }
    else {
        return "未知文件类型";
    }
}