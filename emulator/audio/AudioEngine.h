#pragma once

#include <string>

namespace bachata {
namespace audio {

class AudioEngine {
public:
    bool initialize();
    bool start();
    void stop();
    std::string getBackendName() const;
};

} // namespace audio
} // namespace bachata
