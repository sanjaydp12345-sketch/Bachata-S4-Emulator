#include "MemorySystem.h"

namespace bachata {
namespace memory {

MemorySystem::MemorySystem() = default;
MemorySystem::~MemorySystem() = default;

bool MemorySystem::initialize(std::size_t sizeBytes) {
    memory_.resize(sizeBytes);
    return true;
}

bool MemorySystem::mapRegion(std::uintptr_t guestAddress, std::size_t size, bool readable, bool writable, bool executable) {
    (void)guestAddress;
    (void)size;
    (void)readable;
    (void)writable;
    (void)executable;
    return true;
}

void* MemorySystem::allocatePageAligned(std::size_t size) {
    return std::calloc(size, 1);
}

std::uint8_t* MemorySystem::read(std::uintptr_t guestAddress, std::size_t length) {
    if (guestAddress >= memory_.size()) {
        return nullptr;
    }
    auto offset = static_cast<std::size_t>(guestAddress);
    if (offset + length > memory_.size()) {
        return nullptr;
    }
    return memory_.data() + offset;
}

bool MemorySystem::write(std::uintptr_t guestAddress, const std::uint8_t* data, std::size_t length) {
    if (guestAddress >= memory_.size() || data == nullptr) {
        return false;
    }
    auto offset = static_cast<std::size_t>(guestAddress);
    if (offset + length > memory_.size()) {
        return false;
    }
    std::copy(data, data + length, memory_.begin() + static_cast<std::ptrdiff_t>(offset));
    return true;
}

} // namespace memory
} // namespace bachata
