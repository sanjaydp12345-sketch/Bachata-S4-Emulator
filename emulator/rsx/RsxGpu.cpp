#include "RsxGpu.h"

namespace bachata {
namespace graphics {

RgxRenderer::RgxRenderer() = default;
RgxRenderer::~RgxRenderer() = default;

bool RgxRenderer::initialize(GraphicsBackend backend) {
    backend_ = backend;
    return true;
}

bool RgxRenderer::compileShader(const std::string& source) {
    (void)source;
    return true;
}

void RgxRenderer::renderFrame() {
}

std::string RgxRenderer::getBackendName() const {
    switch (backend_) {
        case GraphicsBackend::Vulkan: return "Vulkan";
        case GraphicsBackend::OpenGLES: return "OpenGL ES";
        default: return "Unknown";
    }
}

} // namespace graphics
} // namespace bachata
