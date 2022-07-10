package com.example.ndkdemo

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private val nativeCaller by lazy {
        NativeCaller()
    }
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        System.loadLibrary("ndk-demo")

        nativeCaller.init(getExternalFilesDir(null)?.absolutePath)
        nativeCaller.nativeLog()
    }
}