#include "AudioEngine.h"

namespace bachata {
namespace audio {

bool AudioEngine::initialize() {
    return true;
}

bool AudioEngine::start() {
    return true;
}

void AudioEngine::stop() {
}

std::string AudioEngine::getBackendName() const {
    return "Android AudioTrack/Oboe";
}

} // namespace audio
} // namespace bachata
