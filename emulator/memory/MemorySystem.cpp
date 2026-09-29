#include "MemorySystem.h"

namespace bachata { namespace memory {
MemorySystem::MemorySystem() = default;
MemorySystem::~MemorySystem() = default;
bool MemorySystem::initialize(std::size_t sizeBytes) { memory_.assign(sizeBytes, 0); return true; }
bool MemorySystem::mapRegion(std::uintptr_t guestAddress, std::size_t size, bool readable, bool writable, bool executable) {
    (void)readable; (void)writable; (void)executable;
    return guestAddress <= memory_.size() && size <= memory_.size() - guestAddress;
}
void* MemorySystem::allocatePageAligned(std::size_t size) { return std::calloc(size, 1); }
std::uint8_t* MemorySystem::read(std::uintptr_t guestAddress, std::size_t length) {
    if (guestAddress > memory_.size() || length > memory_.size() - guestAddress) return nullptr;
    return memory_.data() + guestAddress;
}
bool MemorySystem::write(std::uintptr_t guestAddress, const std::uint8_t* data, std::size_t length) {
    if (data == nullptr || guestAddress > memory_.size() || length > memory_.size() - guestAddress) return false;
    std::copy(data, data + length, memory_.begin() + static_cast<std::ptrdiff_t>(guestAddress));
    return true;
}
}}
