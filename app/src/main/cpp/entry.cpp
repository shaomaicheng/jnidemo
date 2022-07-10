
#include "android/storage_manager.h"
#include "m_file.h"
#include <jni.h>
#include <string>
#include <iostream>

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