#ifndef __DATAEYE_DCLEVELS_H__
#define __DATAEYE_DCLEVELS_H__

class DCLevels
{
public:
	static void begin(int levelNumber, const char* levelId);
	static void complete(const char* levelId);
	static void fail(const char* levelId, const char* failPoint);
private:
    static const char* path;
};

#endif
