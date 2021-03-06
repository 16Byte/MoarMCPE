#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <mcpe/Common.h>

#define LOG_TAG "moarmc"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*)&Common::getGameVersionString, (void*)&Common_getGameVersionString_hook, (void**)&Common_getGameVersionString_real);

	static std::string(*Common_getGameVersionString_real)();
	static std::string Common_getGameVersionString_hook() {
		return "MoarMCPE By 16Byte";
	}

	return JNI_VERSION_1_2;
}


