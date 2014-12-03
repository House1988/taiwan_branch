#ifndef __DATAEYE_DCEVENT_H__
#define __DATAEYE_DCEVENT_H__
#include <jni.h>
#include <map>
#include <string>

using namespace std;

class DCEvent
{
public:
	static void onEventCount(const char* eventId);
	
	static void onEvent(const char* eventId);
	static void onEvent(const char* eventId, const char* label);
	static void onEvent(const char* eventId, map<string, string>* map);
	static void onEvent(const char* eventId, map<string, string>* map, const char* flag);
	
	static void onEventDuration(const char* eventId, long duration);
	static void onEventDuration(const char* eventId, const char* label, long duration);
	static void onEventDuration(const char* eventId, map<string, string>* map, long duration);
	
	static void onEventBegin(const char* eventId);
	static void onEventBegin(const char* eventId, map<string, string>* map);
	static void onEventBegin(const char* eventId, map<string, string>* map, const char* flag);
	static void onEventEnd(const char* eventId);
	static void onEventEnd(const char* eventId, const char* flag);
};
#endif
