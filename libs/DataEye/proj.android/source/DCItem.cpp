#include "DCItem.h"
#include "DCJniHelper.h"

extern jclass jDCItem;

void DCItem::buy(const char* itemId, const char* itemType, int itemCount, int virtualCurrency, const char* currencyType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCItem, "buy", "(Ljava/lang/String;Ljava/lang/String;IILjava/lang/String;)V"))
	{
		jstring jItemId = methodInfo.env->NewStringUTF(itemId);
		jstring jItemType = methodInfo.env->NewStringUTF(itemType);
		jstring jCurrencyType = methodInfo.env->NewStringUTF(currencyType);
		jint jItemCount = itemCount;
		jint jVirtualCurrency = virtualCurrency;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jItemId, jItemType, jItemCount, jVirtualCurrency, jCurrencyType);
		methodInfo.env->DeleteLocalRef(jItemId);
		methodInfo.env->DeleteLocalRef(jItemType);
		methodInfo.env->DeleteLocalRef(jCurrencyType);
	}
}

void DCItem::get(const char* itemId, const char* itemType, int itemCount, const char* reason)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCItem, "get", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V"));
	{
		jstring jItemId = methodInfo.env->NewStringUTF(itemId);
		jstring jItemType = methodInfo.env->NewStringUTF(itemType);
		jstring jReason = methodInfo.env->NewStringUTF(reason);
		jint jItemCount = itemCount;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jItemId, jItemType, jItemCount, jReason);
		methodInfo.env->DeleteLocalRef(jItemId);
		methodInfo.env->DeleteLocalRef(jItemType);
		methodInfo.env->DeleteLocalRef(jReason);
	}
}

void DCItem::consume(const char* itemId, const char* itemType, int itemCount, const char* reason)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCItem, "use", "(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)V"));
	{
		jstring jItemId = methodInfo.env->NewStringUTF(itemId);
		jstring jItemType = methodInfo.env->NewStringUTF(itemType);
		jstring jReason = methodInfo.env->NewStringUTF(reason);
		jint jItemCount = itemCount;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jItemId, jItemType, jItemCount, jReason);
		methodInfo.env->DeleteLocalRef(jItemId);
		methodInfo.env->DeleteLocalRef(jItemType);
		methodInfo.env->DeleteLocalRef(jReason);
	}
}
