#pragma once

#include <string>

namespace bachata {
namespace fs {

class GameFileDetector {
public:
    enum class FileType {
        Iso,
        Pkg,
        Folder,
        Unknown
    };

    static FileType detect(const std::string& path);
    static bool validateStructure(const std::string& path);
};

} // namespace fs
} // namespace bachata
