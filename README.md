# Bachata S4 Emulator

This repository is an Android emulator framework and architecture scaffold for a PS3-style Android application. It is intended to be a clean original project skeleton for a future emulator implementation, not a claim of a complete PlayStation 3 emulator.

## What is included

- Android Studio project layout
- Kotlin UI with a game library and settings screens
- NDK/JNI bridge for native emulator initialization
- C++ native module stubs for CPU, memory, GPU, audio, input and filesystem layers
- Vulkan/OpenGL abstraction placeholders and architecture docs
- Storage import and game-detection interfaces
- Logging and configuration stubs

## Important note

The project is intentionally honest about scope. Full PS3 emulation is a large engineering effort and requires substantial CPU, memory and GPU work. This codebase provides the foundation and staged interfaces needed for iterative development.

## Android build

1. Install Android Studio and Android SDK 34+
2. Open the repository as a project
3. Let Gradle sync
4. Build debug APK or release APK from the IDE
5. If needed, install from Android Studio device manager

## Native module

The native library is named `bachata_emulator` and is connected through JNI using `NativeBridge`.

## Project layout

- `app/` — Android frontend and JNI glue
- `emulator/` — CPU/memory/filesystem/input architecture
- `graphics/` — Vulkan/OpenGL renderer abstraction
- `frontend/` — game library, settings and controller layers
- `docs/` — architecture notes

## Legal / design note

This project does not bundle copyrighted Sony firmware, proprietary game files, encryption keys, game assets, or commercial PS3 titles. It expects users to import legally obtained, dumped game data they own.
