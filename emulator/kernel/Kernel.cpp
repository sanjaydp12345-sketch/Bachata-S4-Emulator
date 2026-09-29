#include "Kernel.h"

namespace bachata {
namespace kernel {

bool Kernel::initialize() {
    return true;
}

std::string Kernel::getKernelName() const {
    return "PS3 kernel stub";
}

} // namespace kernel
} // namespace bachata
