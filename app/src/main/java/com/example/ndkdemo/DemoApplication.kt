package com.example.ndkdemo

import android.app.Application
import com.bytedance.android.bytehook.ByteHook

class DemoApplication: Application() {
    override fun onCreate() {
        super.onCreate()
        ByteHook.init()
        ByteHook.setDebug(true)
    }
}