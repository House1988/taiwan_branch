#ifndef __DCCARDSGAME_H__
#define __DCCARDSGAME_H__

class DCCardsGame
{
public:
	static void play(const char* roomId, const char* id, int loseOrGain, int tax, int left);
	static void gain(const char* roomId, const char* id, int gain, int left);
	static void lost(const char* roomId, const char* id, int lost, int left);
};
#endif