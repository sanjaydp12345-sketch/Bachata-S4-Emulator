#include "InputManager.h"

namespace bachata {
namespace input {

bool InputManager::initialize() {
    return true;
}

bool InputManager::mapButton(std::string from, std::string to) {
    (void)from;
    (void)to;
    return true;
}

std::string InputManager::getMappingSummary() const {
    return "Controller mapping enabled";
}

} // namespace input
} // namespace bachata
