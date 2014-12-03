#ifndef __DATAEYE_DCMONITOR_H__
#define __DATAEYE_DCMONITOR_H__
class DCMonitor
{
public:
	static void addMonitor(const char* monitorName, bool isSucc, long costTime);
};
#endif

