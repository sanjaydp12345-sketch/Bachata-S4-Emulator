#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <vector>

namespace bachata { namespace memory {
class MemorySystem {
public:
    MemorySystem();
    ~MemorySystem();
    bool initialize(std::size_t sizeBytes);
    bool mapRegion(std::uintptr_t guestAddress, std::size_t size, bool readable, bool writable, bool executable);
    void* allocatePageAligned(std::size_t size);
    std::uint8_t* read(std::uintptr_t guestAddress, std::size_t length);
    bool write(std::uintptr_t guestAddress, const std::uint8_t* data, std::size_t length);
private:
    std::vector<std::uint8_t> memory_;
};
}}
