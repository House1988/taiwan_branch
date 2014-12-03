#ifndef __DATAEYE_DCCOIN_H__
#define __DATAEYE_DCCOIN_H__

class DCCoin
{
public: 
	static void setCoinNum(int coinNum, const char* coinType);
	static void lost(const char* id, int lost, int left, const char* coinType);
	static void gain(const char* id, int gain, int left, const char* coinType);
};

#endif