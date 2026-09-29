#include "OpenGLRenderer.h"

namespace bachata {
namespace graphics {

bool OpenGLRenderer::initialize() {
    return true;
}

bool OpenGLRenderer::compileShader(const std::string& source) {
    (void)source;
    return true;
}

std::string OpenGLRenderer::getStatus() const {
    return "OpenGL ES fallback available";
}

} // namespace graphics
} // namespace bachata
