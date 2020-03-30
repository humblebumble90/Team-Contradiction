#include "PlayerEntry.h"

PlayerEntry::PlayerEntry(std::string name, int score)
{
	Name = name;
	Score = score;
}

PlayerEntry::~PlayerEntry()
{
}

std::string PlayerEntry::getName()
{
	return Name;
}

int PlayerEntry::getScore()
{
	return Score;
}
