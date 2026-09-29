#pragma once

#include <string>

namespace bachata {
namespace kernel {

class Kernel {
public:
    bool initialize();
    std::string getKernelName() const;
};

} // namespace kernel
} // namespace bachata
