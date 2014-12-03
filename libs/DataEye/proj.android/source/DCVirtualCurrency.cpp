#include "DCVirtualCurrency.h"
#include <jni.h>
#include "DCJniHelper.h"

extern jclass jDCVirtualCurrency;

void DCVirtualCurrency::onCharge(const char* orderId, const double currencyAmount, const char* currencyType, const char* paymentType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCVirtualCurrency, "onCharge",
		"(Ljava/lang/String;DLjava/lang/String;Ljava/lang/String;)V"))
	{
		jstring jorderId = methodInfo.env->NewStringUTF(orderId);
		jdouble jCurrencyAmount = currencyAmount;
		jstring jcurrencyType = methodInfo.env->NewStringUTF(currencyType);
		jstring jpaymentType = methodInfo.env->NewStringUTF(paymentType);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jorderId, jCurrencyAmount,
				jcurrencyType, jpaymentType);
		methodInfo.env->DeleteLocalRef(jorderId);
		methodInfo.env->DeleteLocalRef(jcurrencyType);
		methodInfo.env->DeleteLocalRef(jpaymentType);
	}
}

void DCVirtualCurrency::onChargeSuccess(const char* orderId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCVirtualCurrency, "onChargeSuccess", "(Ljava/lang/String;)V"))
	{
		jstring jorderId = methodInfo.env->NewStringUTF(orderId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jorderId);
		methodInfo.env->DeleteLocalRef(jorderId);
	}
}

void DCVirtualCurrency::onChargeOnlySuccess(const double currencyAmount, const char* currencyType, const char* paymentType)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCVirtualCurrency, "onChargeOnlySuccess",
		"(DLjava/lang/String;Ljava/lang/String;)V"))
	{
		jdouble jCurrencyAmount = currencyAmount;
		jstring jcurrencyType = methodInfo.env->NewStringUTF(currencyType);
		jstring jpaymentType = methodInfo.env->NewStringUTF(paymentType);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jCurrencyAmount, jcurrencyType, jpaymentType);
		methodInfo.env->DeleteLocalRef(jcurrencyType);
		methodInfo.env->DeleteLocalRef(jpaymentType);
	}
}
