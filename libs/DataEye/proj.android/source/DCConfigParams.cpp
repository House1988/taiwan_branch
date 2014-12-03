#include "DCConfigParams.h"
#include "DCJniHelper.h"

using namespace cocos2d;

extern jclass jDCConfigParams;

extern "C"
{
    JNIEXPORT void JNICALL Java_com_dataeye_DCCocos2dConfigParams_updateSuccess(JNIEnv *, jobject obj)
    {
        CCNotificationCenter::sharedNotificationCenter()->postNotification(DCCONFIGPARAMS_UPDATE_SUCCESS);
    }
}

void DCConfigParams::update()
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCConfigParams, "update", "()V"))
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
}

const char* DCConfigParams::getParameterString(const char* key, const char* defaultValue)
{
    static std::string ret = "";
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCConfigParams, "getParameterString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"))
	{
		jstring jkey = methodInfo.env->NewStringUTF(key);
		jstring jdefaultValue = methodInfo.env->NewStringUTF(defaultValue);
		jstring result = (jstring)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, jkey, jdefaultValue);
		ret = DCJniHelper::jstring2string(result);
		methodInfo.env->DeleteLocalRef(jkey);
		methodInfo.env->DeleteLocalRef(jdefaultValue);
		return ret.c_str();
	}
}

int DCConfigParams::getParameterInt(const char* key, int defaultValue)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCConfigParams, "getParameterInt", "(Ljava/lang/String;I)I"))
	{
		jstring jkey = methodInfo.env->NewStringUTF(key);
		jint jdefaultValue = defaultValue;
		jint result = methodInfo.env->CallStaticIntMethod(methodInfo.classID, methodInfo.methodID, jkey, jdefaultValue);
		methodInfo.env->DeleteLocalRef(jkey);
		return (int)result;
	}
}

bool DCConfigParams::getParameterBool(const char* key, bool defaultValue)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCConfigParams, "getParameterBoolean", "(Ljava/lang/String;Z)Z"))
	{
		jstring jkey = methodInfo.env->NewStringUTF(key);
		jboolean jdefaultValue = defaultValue;
		jboolean result = methodInfo.env->CallStaticBooleanMethod(methodInfo.classID, methodInfo.methodID, jkey, jdefaultValue);
		methodInfo.env->DeleteLocalRef(jkey);
		return (bool)result;
	}
}