#pragma once

#include <string>

namespace bachata {
namespace emulator {

class SpuCore {
public:
    bool initialize();
    std::string getId() const;
};

} // namespace emulator
} // namespace bachata
