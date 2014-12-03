#include "DCAccount.h"
#include <jni.h>
#include <DCJniHelper.h>
#include <android/log.h>

extern jclass jDCAccount;

void DCAccount::login()
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "login", "()V"))
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
}

void DCAccount::login(const char* accountId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "login", "(Ljava/lang/String;)V"))
	{
		jstring jaccountId = methodInfo.env->NewStringUTF(accountId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jaccountId);
		methodInfo.env->DeleteLocalRef(jaccountId);
	}
}

void DCAccount::logout()
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "logout", "()V"))
	{
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
	}
}

void DCAccount::setAccountType(AccountType accountType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "setAccountType", "(I)V"))
	{
		jint jType = accountType;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jType);
	}
}

void DCAccount::setLevel(int level)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "setLevel", "(I)V"))
	{
		jint jLevel = level;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jLevel);
	}
}

void DCAccount::setGender(Gender gender)
{
	DCJniMethodInfo methodInfo;
	DCJniMethodInfo mi;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "setGender", "(I)V"))
	{
		jint jGender = gender;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jGender);
	}
}

void DCAccount::setAge(int age)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "setAge", "(I)V"))
	{
		jint jAge = age;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jAge);
	}
}

void DCAccount::setGameServer(const char* gameServer)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "setGameServer", "(Ljava/lang/String;)V"))
	{
		jstring jgameServer = methodInfo.env->NewStringUTF(gameServer);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jgameServer);
		methodInfo.env->DeleteLocalRef(jgameServer);
	}
}

void DCAccount::tag(const char* tag)
{
    DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "tag", "(Ljava/lang/String;)V"))
	{
		jstring jtag = methodInfo.env->NewStringUTF(tag);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jtag);
		methodInfo.env->DeleteLocalRef(jtag);
	}
}

void DCAccount::unTag(const char* tag)
{
    DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCAccount, "unTag", "(Ljava/lang/String;)V"))
	{
		jstring jtag = methodInfo.env->NewStringUTF(tag);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jtag);
		methodInfo.env->DeleteLocalRef(jtag);
	}
}

