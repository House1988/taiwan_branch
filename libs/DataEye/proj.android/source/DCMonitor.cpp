#include "DCMonitor.h"
#include "DCJniHelper.h"

extern jclass jDCMonitor;

void DCMonitor::addMonitor(const char* monitorName, bool isSucc, long costTime)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCMonitor, "addMonitor", "(Ljava/lang/String;ZJ)V"))
	{
		jstring jmonitorName = methodInfo.env->NewStringUTF(monitorName);
		jboolean jIsSucc = isSucc;
		jlong jCostTime = costTime;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jmonitorName, jIsSucc, jCostTime);
		methodInfo.env->DeleteLocalRef(jmonitorName);
	}
}
