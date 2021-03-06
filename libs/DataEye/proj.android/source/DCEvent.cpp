#include "DCEvent.h"
#include "DCJniHelper.h"
#include <android/log.h>

extern jclass jDCEvent;

void DCEvent::onEventCount(const char* eventId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventCount", "(Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId);
		methodInfo.env->DeleteLocalRef(jEventId);
	}
}

void DCEvent::onEvent(const char* eventId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEvent", "(Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId);
		methodInfo.env->DeleteLocalRef(jEventId);
	}
}

void DCEvent::onEvent(const char* eventId, const char* label)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEvent", "(Ljava/lang/String;Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jstring jLabel = methodInfo.env->NewStringUTF(label);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jLabel);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jLabel);
	}
}

void DCEvent::onEvent(const char* eventId, map<string, string>* map)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEvent", "(Ljava/lang/String;Ljava/util/Map;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jobject jmap = DCJniHelper::cMapToJMap(map);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jmap);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jmap);
	}
}

void DCEvent::onEvent(const char* eventId, map<string, string>* map, const char* flag)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEvent", "(Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jobject jmap = DCJniHelper::cMapToJMap(map);
		jstring jFlag = methodInfo.env->NewStringUTF(flag);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jmap, jFlag);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jmap);
		methodInfo.env->DeleteLocalRef(jFlag);
	}
}

void DCEvent::onEventDuration(const char* eventId, long duration)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventDuration", "(Ljava/lang/String;J)V"))
	{
		jlong jduration = duration;
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jduration);
		methodInfo.env->DeleteLocalRef(jEventId);
	}
}

void DCEvent::onEventDuration(const char* eventId, const char* label, long duration)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventDuration", "(Ljava/lang/String;Ljava/lang/String;J)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jstring jLabel = methodInfo.env->NewStringUTF(label);
		jlong jduration = duration;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jLabel, jduration);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jLabel);
	}
}

void DCEvent::onEventDuration(const char* eventId, map<string, string>* map, long duration)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventDuration", "(Ljava/lang/String;Ljava/util/Map;J)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jobject jmap = DCJniHelper::cMapToJMap(map);
		jlong jduration = duration;
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jmap, jduration);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jmap);
	}
}

void DCEvent::onEventBegin(const char* eventId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventBegin", "(Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId);
		methodInfo.env->DeleteLocalRef(jEventId);
	}
}

void DCEvent::onEventBegin(const char* eventId, map<string, string>* map)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventBegin", "(Ljava/lang/String;Ljava/util/Map;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jobject jmap = DCJniHelper::cMapToJMap(map);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jmap);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jmap);
	}
}

void DCEvent::onEventBegin(const char* eventId, map<string, string>* map, const char* flag)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventBegin", "(Ljava/lang/String;Ljava/util/Map;Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jobject jmap = DCJniHelper::cMapToJMap(map);
		jstring jFlag = methodInfo.env->NewStringUTF(flag);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jmap, jFlag);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jmap);
		methodInfo.env->DeleteLocalRef(jFlag);
	}
}

void DCEvent::onEventEnd(const char* eventId)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventEnd", "(Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId);
		methodInfo.env->DeleteLocalRef(jEventId);
	}
}

void DCEvent::onEventEnd(const char* eventId, const char* flag)
{
	DCJniMethodInfo methodInfo;
	if(DCJniHelper::getStaticMethodInfo(methodInfo, jDCEvent, "onEventEnd", "(Ljava/lang/String;Ljava/lang/String;)V"))
	{
		jstring jEventId = methodInfo.env->NewStringUTF(eventId);
		jstring jFlag = methodInfo.env->NewStringUTF(flag);
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, jEventId, jFlag);
		methodInfo.env->DeleteLocalRef(jEventId);
		methodInfo.env->DeleteLocalRef(jFlag);
	}
}
