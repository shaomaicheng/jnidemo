
#include "android/storage_manager.h"
#include "m_file.h"
#include <jni.h>
#include <string>
#include <iostream>
#include "bytehook.h"

using namespace std;

//com.example.ndkdemo
extern "C" JNIEXPORT void JNICALL
Java_com_example_ndkdemo_NativeCaller_nativeLog(JNIEnv *env, jobject thiz) {
    const char *apilevel = (to_string(android_get_device_api_level()).c_str());
    const char *targetsdkversion = (to_string(
            android_get_application_target_sdk_version()).c_str());
    LOGE("apilevel:%s,targetsdkversion:%s", apilevel, targetsdkversion);
    LOGE("存储目录:%s", MFileOperator::FILE_NAME.c_str());
    MFileOperator *fileOperator = new MFileOperator();
    fileOperator->operatorFile();
    delete fileOperator;

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_NativeCaller_init(JNIEnv *env, jobject thiz, jstring path) {
    if (path != NULL) {
        // jstring 转换成string
        const char *retChar = env->GetStringUTFChars(path, 0);
        string retStr = retChar;
        MFileOperator::initMinePath(retStr);
    }
}


bytehook_stub_t stub = nullptr;



int my_androidlevel() {
    BYTEHOOK_STACK_SCOPE(); // 不能省略
    __android_log_print(ANDROID_LOG_ERROR, "chenglei", "这是hook过的，开始调用 android_get_application_target_sdk_version");
    int result = BYTEHOOK_CALL_PREV(my_androidlevel);
    __android_log_print(ANDROID_LOG_ERROR, "chenglei", "这是hook过的，结束调用 android_get_application_target_sdk_version");
    return result;
//    return 0;
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_NativeCaller_hook(JNIEnv *env, jobject thiz) {

    stub = bytehook_hook_all(nullptr, "android_get_application_target_sdk_version", reinterpret_cast<void *>(my_androidlevel), nullptr,
                             nullptr);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_ndkdemo_NativeCaller_callNativeAndroidLevel(JNIEnv *env, jobject thiz) {
//    __android_log_print(ANDROID_LOG_ERROR, "chenglei", "调用android_get_device_api_level");
    int ret = android_get_application_target_sdk_version();
    __android_log_print(ANDROID_LOG_ERROR, "chenglei", "当前api版本：%d", ret);
}