#pragma once

#include <string>

namespace bachata {
namespace input {

class InputManager {
public:
    bool initialize();
    bool mapButton(std::string from, std::string to);
    std::string getMappingSummary() const;
};

} // namespace input
} // namespace bachata
