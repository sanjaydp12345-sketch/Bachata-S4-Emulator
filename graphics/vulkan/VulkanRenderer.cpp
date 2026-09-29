#include "VulkanRenderer.h"

namespace bachata {
namespace graphics {

VulkanRenderer::VulkanRenderer() = default;
VulkanRenderer::~VulkanRenderer() = default;

bool VulkanRenderer::initialize() {
    initialized_ = true;
    return true;
}

bool VulkanRenderer::createSwapchain() {
    return initialized_;
}

bool VulkanRenderer::compileShader(const std::string& source) {
    (void)source;
    return initialized_;
}

void VulkanRenderer::renderFrame() {
}

std::string VulkanRenderer::getStatus() const {
    return initialized_ ? "Vulkan renderer initialized" : "Vulkan not initialized";
}

} // namespace graphics
} // namespace bachata
