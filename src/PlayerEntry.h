#pragma once
#include <string>
#ifndef __PLAYER_ENTRY__
#define __PLAYER_ENTRY__
class PlayerEntry
{
public:
	PlayerEntry(std::string name, int score);
	~PlayerEntry();
	std::string getName();
	int getScore();

private:
	std::string Name;
	int Score;
};
#endif/*Defined(__PLAYER_ENTRY__)*/
