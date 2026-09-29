#include "GameFileDetector.h"

namespace bachata {
namespace fs {

GameFileDetector::FileType GameFileDetector::detect(const std::string& path) {
    const std::string lower = path;
    if (lower.find(".iso") != std::string::npos) {
        return FileType::Iso;
    }
    if (lower.find(".pkg") != std::string::npos) {
        return FileType::Pkg;
    }
    if (lower.empty()) {
        return FileType::Unknown;
    }
    return FileType::Folder;
}

bool GameFileDetector::validateStructure(const std::string& path) {
    (void)path;
    return true;
}

} // namespace fs
} // namespace bachata
