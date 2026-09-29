#pragma once

#include <string>

namespace bachata {
namespace graphics {

enum class GraphicsBackend {
    Vulkan,
    OpenGLES,
    Unknown
};

class RgxRenderer {
public:
    RgxRenderer();
    ~RgxRenderer();

    bool initialize(GraphicsBackend backend);
    bool compileShader(const std::string& source);
    void renderFrame();
    std::string getBackendName() const;

private:
    GraphicsBackend backend_ = GraphicsBackend::Unknown;
};

} // namespace graphics
} // namespace bachata
