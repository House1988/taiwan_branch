#ifndef __DATAEYE_DCVIRTUALCURRENCY_H__
#define __DATAEYE_DCVIRTUALCURRENCY_H__
class DCVirtualCurrency
{
public:

	static void onCharge(const char* orderId, const double currencyAmount, const char* currencyType, const char* paymentType);

	static void onChargeSuccess(const char* orderId);
	
	static void onChargeOnlySuccess(const double currencyAmount, const char* currencyType, const char* paymentType);
};
#endif

