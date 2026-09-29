package com.bachatas4.emulator

import android.content.Context
import android.net.Uri
import android.provider.OpenableColumns
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.compose.foundation.background
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Add
import androidx.compose.material.icons.filled.PlayArrow
import androidx.compose.material.icons.filled.Settings
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBar
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import java.util.Locale

private data class GameEntry(
    val title: String,
    val serial: String,
    val region: String,
    val fileType: String,
    val filePath: String,
    val sizeBytes: Long
)

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun BachataS4App() {
    val context = LocalContext.current
    val games = remember { mutableStateListOf<GameEntry>() }
    var activeTab by remember { mutableStateOf("Games") }
    var message by remember { mutableStateOf("Select Add Game to import legally dumped data.") }

    val openDocument = rememberLauncherForActivityResult(
        ActivityResultContracts.OpenDocument()
    ) { uri: Uri? ->
        uri ?: return@rememberLauncherForActivityResult
        context.contentResolver.takePersistableUriPermission(
            uri,
            android.content.Intent.FLAG_GRANT_READ_URI_PERMISSION
        )
        val name = displayName(context, uri) ?: "Imported game"
        val type = when {
            name.lowercase(Locale.US).endsWith(".iso") -> "ISO"
            name.lowercase(Locale.US).endsWith(".pkg") -> "PKG"
            else -> "FILE"
        }
        val size = querySize(context, uri)
        games.add(GameEntry(name.substringBeforeLast('.'), "UNKNOWN", "Unknown", type, uri.toString(), size))
        message = "$type imported. Basic validation is complete; full PS3 compatibility is not implemented yet."
    }

    Scaffold(topBar = {
        TopAppBar(
            title = { Text("Bachata S4") },
            actions = {
                IconButton(onClick = { openDocument.launch(arrayOf("application/octet-stream", "*/*")) }) {
                    Icon(Icons.Filled.Add, "Add game")
                }
                IconButton(onClick = { activeTab = "Settings" }) {
                    Icon(Icons.Filled.Settings, "Settings")
                }
            }
        )
    }) { padding ->
        Column(
            Modifier.fillMaxSize().background(Color(0xFF0B1020)).padding(padding).padding(16.dp)
        ) {
            Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.spacedBy(8.dp)) {
                listOf("Games", "Recent", "Favorites", "Settings").forEach { tab ->
                    Button(onClick = { activeTab = tab }) { Text(tab) }
                }
            }
            Text(message, color = Color.LightGray, modifier = Modifier.padding(vertical = 12.dp))
            when (activeTab) {
                "Games", "Recent", "Favorites" -> LazyColumn(
                    Modifier.fillMaxSize(), verticalArrangement = Arrangement.spacedBy(12.dp)
                ) { items(games) { GameCard(it) { message = "The native core is a staged framework; this game cannot be executed yet." } } }
                "Settings" -> SettingsPanel()
            }
        }
    }
}

@Composable
private fun GameCard(game: GameEntry, onPlay: () -> Unit) {
    Card(Modifier.fillMaxWidth(), colors = CardDefaults.cardColors(containerColor = MaterialTheme.colorScheme.surfaceVariant)) {
        Column(Modifier.padding(16.dp)) {
            Text(game.title, style = MaterialTheme.typography.headlineSmall)
            Text("Serial: ${game.serial} | Region: ${game.region}")
            Text("${game.fileType} | ${formatBytes(game.sizeBytes)}")
            Text(game.filePath, maxLines = 1)
            Row(Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.End) {
                Button(onClick = onPlay) {
                    Icon(Icons.Filled.PlayArrow, "Play")
                    Text("PLAY")
                }
            }
        }
    }
}

@Composable
private fun SettingsPanel() {
    Surface(Modifier.fillMaxWidth().padding(top = 16.dp), color = MaterialTheme.colorScheme.surfaceVariant) {
        Column(Modifier.padding(20.dp), verticalArrangement = Arrangement.spacedBy(8.dp)) {
            Text("Graphics: Vulkan primary / OpenGL ES fallback")
            Text("Performance: Balanced | Frame limit: Auto")
            Text("Audio: Android AudioTrack backend")
            Text("Input: touchscreen, Bluetooth and USB gamepads")
            Text("Storage: Android Storage Access Framework")
            Text("Native CPU/GPU execution: staged interfaces only")
        }
    }
}

private fun displayName(context: Context, uri: Uri): String? = context.contentResolver.query(uri, arrayOf(OpenableColumns.DISPLAY_NAME), null, null, null)?.use {
    if (it.moveToFirst()) it.getString(0) else null
}

private fun querySize(context: Context, uri: Uri): Long = context.contentResolver.query(uri, arrayOf(OpenableColumns.SIZE), null, null, null)?.use {
    if (it.moveToFirst() && !it.isNull(0)) it.getLong(0) else 0L
} ?: 0L

private fun formatBytes(bytes: Long): String = when {
    bytes <= 0 -> "size unknown"
    bytes < 1024L * 1024L -> "$bytes B"
    bytes < 1024L * 1024L * 1024L -> "%.1f MB".format(Locale.US, bytes / 1024f / 1024f)
    else -> "%.2f GB".format(Locale.US, bytes / 1024f / 1024f / 1024f)
}
