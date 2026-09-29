#include "CellCpu.h"

namespace bachata {
namespace emulator {

CellCpu::CellCpu() = default;
CellCpu::~CellCpu() = default;

bool CellCpu::initialize() {
    initialized_ = true;
    return true;
}

bool CellCpu::boot() {
    if (!initialized_) {
        return false;
    }
    running_ = true;
    return true;
}

void CellCpu::step() {
    if (!running_) {
        return;
    }
}

void CellCpu::pause() {
    running_ = false;
}

void CellCpu::resume() {
    running_ = true;
}

std::string CellCpu::getStateSummary() const {
    return "Cell CPU initialized";
}

} // namespace emulator
} // namespace bachata
