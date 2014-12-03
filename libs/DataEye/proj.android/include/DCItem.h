#ifndef __DATAEYE_DCITEM_H__
#define __DATAEYE_DCITEM_H__

class DCItem
{
public:
	static void buy(const char* itemId, const char* itemType, int itemCount, int virtualCurrency, const char* currencyType);
	static void get(const char* itemId, const char* itemType, int itemCount, const char* reason);
	static void consume(const char* itemId, const char* itemType, int itemCount, const char* reason);
};

#endif

