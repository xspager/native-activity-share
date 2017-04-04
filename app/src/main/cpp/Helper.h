#pragma once

#include <string>
#include <jni.h>
#include <string>
#include <android_native_app_glue.h>

class Intent {
public:
    Intent(jobject intent, JNIEnv *env);
    std::string getAction();
    std::string getType();
    std::string getStringExtra(const char* name);
    std::string getConst(const char * name);

private:
    JNIEnv *env;
    jobject javaIntentObj;
    jclass javaIntentClass;

    jmethodID getActionID;
    jmethodID getTypeID;
    jmethodID getStringExtraID;
};