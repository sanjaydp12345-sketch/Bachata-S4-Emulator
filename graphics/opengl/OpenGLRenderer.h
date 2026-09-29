#pragma once

#include <string>

namespace bachata {
namespace graphics {

class OpenGLRenderer {
public:
    bool initialize();
    bool compileShader(const std::string& source);
    std::string getStatus() const;
};

} // namespace graphics
} // namespace bachata
