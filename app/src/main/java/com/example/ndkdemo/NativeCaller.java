package com.example.ndkdemo;

import androidx.annotation.Nullable;

public class NativeCaller {
    public native void init(@Nullable String path);

    public native void nativeLog();
}
