#include <jni.h>
#include <atomic>
#include <string>

namespace {
std::atomic_bool initialized{false};
std::atomic_bool running{false};
std::string loadedPath;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_initializeEmulator(JNIEnv*, jobject) {
    initialized = true;
    return JNI_TRUE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_loadGame(JNIEnv* env, jobject, jstring path) {
    if (!initialized || path == nullptr) return JNI_FALSE;
    const char* chars = env->GetStringUTFChars(path, nullptr);
    loadedPath = chars == nullptr ? "" : chars;
    if (chars != nullptr) env->ReleaseStringUTFChars(path, chars);
    return loadedPath.empty() ? JNI_FALSE : JNI_TRUE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_startEmulation(JNIEnv*, jobject) {
    if (!initialized || loadedPath.empty()) return JNI_FALSE;
    running = true;
    return JNI_TRUE;
}

extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_pauseEmulation(JNIEnv*, jobject) { running = false; return JNI_TRUE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_resumeEmulation(JNIEnv*, jobject) { if (!initialized) return JNI_FALSE; running = true; return JNI_TRUE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_stopEmulation(JNIEnv*, jobject) { running = false; loadedPath.clear(); return JNI_TRUE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_saveState(JNIEnv*, jobject, jint slot) { return initialized && slot >= 0 && slot < 10 ? JNI_TRUE : JNI_FALSE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_loadState(JNIEnv*, jobject, jint slot) { return initialized && slot >= 0 && slot < 10 ? JNI_TRUE : JNI_FALSE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_setGraphicsBackend(JNIEnv*, jobject, jstring) { return initialized ? JNI_TRUE : JNI_FALSE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_setFrameLimit(JNIEnv*, jobject, jint fps) { return initialized && (fps == 0 || fps == 30 || fps == 60) ? JNI_TRUE : JNI_FALSE; }
extern "C" JNIEXPORT jboolean JNICALL
Java_com_bachatas4_emulator_NativeBridge_setResolution(JNIEnv*, jobject, jfloat scale) { return initialized && scale > 0.0f && scale <= 4.0f ? JNI_TRUE : JNI_FALSE; }
