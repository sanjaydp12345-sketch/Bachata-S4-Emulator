#pragma once

#include <string>

namespace bachata {
namespace graphics {

enum class VulkanResult {
    Success,
    Failed,
    Unsupported
};

class VulkanRenderer {
public:
    VulkanRenderer();
    ~VulkanRenderer();

    bool initialize();
    bool createSwapchain();
    bool compileShader(const std::string& source);
    void renderFrame();
    std::string getStatus() const;

private:
    bool initialized_ = false;
};

} // namespace graphics
} // namespace bachata
