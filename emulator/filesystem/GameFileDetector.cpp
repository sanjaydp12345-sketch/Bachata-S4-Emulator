#include "GameFileDetector.h"
#include <algorithm>
#include <cctype>

namespace bachata { namespace fs {
static std::string lower(std::string value) {
    std::transform(value.begin(), value.end(), value.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return value;
}
GameFileDetector::FileType GameFileDetector::detect(const std::string& path) {
    const auto value = lower(path);
    if (value.size() >= 4 && value.ends_with(".iso")) return FileType::Iso;
    if (value.size() >= 4 && value.ends_with(".pkg")) return FileType::Pkg;
    return value.empty() ? FileType::Unknown : FileType::Folder;
}
bool GameFileDetector::validateStructure(const std::string& path) { return !path.empty(); }
}}
