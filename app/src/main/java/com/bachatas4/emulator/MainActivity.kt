package com.bachatas4.emulator

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.material3.MaterialTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            MaterialTheme(
                colorScheme = MaterialTheme.colorScheme,
                typography = MaterialTheme.typography
            ) {
                BachataS4App()
            }
        }
    }
}
