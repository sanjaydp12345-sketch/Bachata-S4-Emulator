#pragma once

#include <cstdint>
#include <string>

namespace bachata {
namespace emulator {

class CellCpu {
public:
    CellCpu();
    ~CellCpu();

    bool initialize();
    bool boot();
    void step();
    void pause();
    void resume();
    std::string getStateSummary() const;

private:
    bool initialized_ = false;
    bool running_ = false;
};

} // namespace emulator
} // namespace bachata
