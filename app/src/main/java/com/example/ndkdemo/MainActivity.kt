package com.example.ndkdemo

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private val nativeCaller by lazy {
        NativeCaller()
    }

    private val hook by lazy {
        findViewById<Button>(R.id.hook)
    }

    private val callStrlen by lazy {
        findViewById<Button>(R.id.callStrlen)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        System.loadLibrary("ndk-demo")

        nativeCaller.init(getExternalFilesDir(null)?.absolutePath)
        nativeCaller.nativeLog()

        hook.setOnClickListener {
            nativeCaller.hook()
        }

        callStrlen.setOnClickListener {
            nativeCaller.callNativeAndroidLevel()
        }
    }
}