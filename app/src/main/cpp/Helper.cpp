#include "Helper.h"

Intent::Intent(jobject intent, JNIEnv *env) {
    javaIntentObj = intent;
    this->env = env;
    javaIntentClass = env->GetObjectClass(intent); //class pointer of Intent

    getActionID = env->GetMethodID(javaIntentClass, "getAction", "()Ljava/lang/String;");
    getTypeID = env->GetMethodID(javaIntentClass, "getType", "()Ljava/lang/String;");
    getStringExtraID = env->GetMethodID(javaIntentClass, "getStringExtra", "(Ljava/lang/String;)Ljava/lang/String;");
}

std::string Intent::getConst(const char *name) {
    jfieldID jid = env->GetFieldID(javaIntentClass, name, "Landroid/content/Intent;");

}

std::string Intent::getAction() {
    jstring s = (jstring) env->CallObjectMethod(javaIntentObj, getActionID);
    if(s != nullptr){
        return std::string(env->GetStringUTFChars(s, 0));
    } else {
        return "";
    }
}

std::string Intent::getType() {
    jstring s = (jstring) env->CallObjectMethod(javaIntentObj, getTypeID);
    if(s!= nullptr){
        return std::string(env->GetStringUTFChars(s, 0));
    } else {
        return "";
    }
}

std::string Intent::getStringExtra(const char *name) {

    jstring s = (jstring) env->CallObjectMethod(javaIntentObj, getStringExtraID, env->NewStringUTF(name));
    if(s != NULL){
        return std::string(env->GetStringUTFChars(s, 0));
    } else {
        return "";
    }
}