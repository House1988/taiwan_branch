#ifndef cocos2dx_DCAccount_h
#define cocos2dx_DCAccount_h
#include "AccountType.h"
#include "Gender.h"

class DCAccount {
public:
	static void login();
	static void login(const char* accountId);
	static void logout();
	static void setAccountType(AccountType accountType);
	static void setLevel(int level);
	static void setGender(Gender gender);
	static void setAge(int age);
	static void setGameServer(const char* gameServer);
	static void tag(const char* tag);
	static void unTag(const char* tag);
};
#endif