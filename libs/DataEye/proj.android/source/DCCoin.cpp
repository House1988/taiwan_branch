#include "DCCoin.h"
#include "DCJniHelper.h"

extern jclass jDCCoin;

void DCCoin::setCoinNum(int coinNum, const char* coinType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCoin, "setCoinNum", "(ILjava/lang/String;)V"))
	{
		jint jCoinNum = coinNum;
        jstring jCoinType = methodInfo.env->NewStringUTF(coinType);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jCoinNum, jCoinType);
        methodInfo.env->DeleteLocalRef(jCoinType);
	}
}

void DCCoin::lost(const char* id, int lost, int left, const char* coinType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCoin, "lost", "(Ljava/lang/String;Ljava/lang/String;II)V"))
	{
		jint jLost = lost;
		jint jLeft = left;
		jstring jId = methodInfo.env->NewStringUTF(id);
        jstring jCoinType = methodInfo.env->NewStringUTF(coinType);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jId, jCoinType, jLost, jLeft);
		methodInfo.env->DeleteLocalRef(jId);
        methodInfo.env->DeleteLocalRef(jCoinType);
	}
}

void DCCoin::gain(const char* id, int gain, int left, const char* coinType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCoin, "gain", "(Ljava/lang/String;Ljava/lang/String;II)V"))
	{
		jint jGain = gain;
		jint jLeft = left;
		jstring jId = methodInfo.env->NewStringUTF(id);
        jstring jCoinType = methodInfo.env->NewStringUTF(coinType);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jId, jCoinType, jGain, jLeft);
		methodInfo.env->DeleteLocalRef(jId);
        methodInfo.env->DeleteLocalRef(jCoinType);
	}
}
