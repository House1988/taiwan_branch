#ifndef __DATAEYE_DCTASK_H__
#define __DATAEYE_DCTASK_H__
#include "TaskType.h"

class DCTask
{
public:
	static void begin(const char* taskId, TaskType taskType);
	static void complete(const char* taskId);
	static void fail(const char* taskId, const char* reason);
};

#endif
