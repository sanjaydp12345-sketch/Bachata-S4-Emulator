# Build status

The repository now contains a buildable Android application shell with:

- Kotlin/Compose library UI
- SAF document import for ISO and PKG-like files
- ARM64 NDK configuration
- CMake/JNI native library with lifecycle methods
- Corrected native C++ headers and bounds checks
- No bundled games, firmware, keys, or copyrighted assets

## What is not implemented

This is not yet a functioning PS3 emulator. The native methods are lifecycle scaffolding only. PPU/SPU instruction execution, RSX command emulation, firmware/syscall support, PKG installation semantics, Vulkan rendering, audio streaming, save-state serialization, and broad game compatibility still require substantial implementation and testing.

## Build

Open in Android Studio, install SDK 34 and NDK 26.3.11579264, sync Gradle, then select `app` and build either `assembleDebug` or `assembleRelease`. The output is under `app/build/outputs/apk/`.
