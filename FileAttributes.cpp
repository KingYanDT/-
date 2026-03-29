#include "FileAttributes.h"
#include <iostream>
#include <filesystem>
#include <chrono>
#include <ctime>  // 必须包含这个头文件以使用 ctime_s

namespace fs = std::filesystem;

void FileAttributes::showFileAttributes(const std::string& filePath) {
    fs::path p(filePath);  // 创建文件路径对象
    if (fs::exists(p)) {  // 检查文件是否存在
        std::cout << "文件存在: " << filePath << std::endl;
        std::cout << "文件大小: " << fs::file_size(p) << " 字节" << std::endl;

        // 转换为系统时间并输出
        auto ftime = fs::last_write_time(p);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(ftime - std::filesystem::file_time_type::clock::now() + std::chrono::system_clock::now());
        std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);  // 转换为 std::time_t 类型

        // 使用 std::ctime_s 格式化时间
        char timeBuffer[26];  // 创建一个缓冲区来存储格式化后的时间字符串
        ctime_s(timeBuffer, sizeof(timeBuffer), &cftime);  // 使用 ctime_s 安全地格式化时间
        std::cout << "最后修改时间: " << timeBuffer << std::endl;  // 输出文件最后修改时间

        std::cout << "是否是只读文件: "
            << ((fs::status(p).permissions() & fs::perms::owner_write) == fs::perms::none ? "是" : "否")
            << std::endl;  // 判断文件是否为只读
    }
    else {
        std::cout << "文件不存在!" << std::endl;  // 如果文件不存在，输出提示
    }
}