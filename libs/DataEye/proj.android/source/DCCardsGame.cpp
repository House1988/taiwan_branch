#include "DCCardsGame.h"
#include "DCJniHelper.h"

extern jclass jDCCardGame;

void DCCardsGame::play(const char* roomId, const char* id, int loseOrGain, int tax, int left)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCardGame, "play", "(Ljava/lang/String;Ljava/lang/String;III)V"))
	{
		jstring jRoomId = methodInfo.env->NewStringUTF(roomId);
		jstring jId = methodInfo.env->NewStringUTF(id);
		jint jLoseOrGain = loseOrGain;
		jint jTax = tax;
		jint jLeft = left;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jRoomId, jId, jLoseOrGain, jTax, jLeft);
		methodInfo.env->DeleteLocalRef(jRoomId);
		methodInfo.env->DeleteLocalRef(jId);
	}
}

void DCCardsGame::lost(const char* roomId, const char* id, int lost, int left)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCardGame, "lost", "(Ljava/lang/String;Ljava/lang/String;II)V"))
	{
		jstring jRoomId = methodInfo.env->NewStringUTF(roomId);
		jstring jId = methodInfo.env->NewStringUTF(id);
		jint jLost = lost;
		jint jLeft = left;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jRoomId, jId, jLost, jLeft);
		methodInfo.env->DeleteLocalRef(jRoomId);
		methodInfo.env->DeleteLocalRef(jId);
	}
}

void DCCardsGame::gain(const char* roomId, const char* id, int gain, int left)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCCardGame, "gain", "(Ljava/lang/String;Ljava/lang/String;II)V"))
	{
		jstring jRoomId = methodInfo.env->NewStringUTF(roomId);
		jstring jId = methodInfo.env->NewStringUTF(id);
		jint jGain = gain;
		jint jLeft = left;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jRoomId, jId, jGain, jLeft);
		methodInfo.env->DeleteLocalRef(jRoomId);
		methodInfo.env->DeleteLocalRef(jId);
	}
}