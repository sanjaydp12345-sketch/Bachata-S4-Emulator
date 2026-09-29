package com.bachatas4.emulator

object NativeBridge {
    init {
        System.loadLibrary("bachata_emulator")
    }

    external fun initializeEmulator(): Boolean
    external fun loadGame(path: String): Boolean
    external fun startEmulation(): Boolean
    external fun pauseEmulation(): Boolean
    external fun resumeEmulation(): Boolean
    external fun stopEmulation(): Boolean
    external fun saveState(slot: Int): Boolean
    external fun loadState(slot: Int): Boolean
    external fun setGraphicsBackend(backend: String): Boolean
    external fun setFrameLimit(fps: Int): Boolean
    external fun setResolution(scale: Float): Boolean
}
