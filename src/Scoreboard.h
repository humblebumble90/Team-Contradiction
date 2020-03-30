#pragma once
#ifndef __SCOREBOARD__
#define __SCOREBOARD__
#include <string>
#include "PlayerEntry.h"
#include <vector>

class Scoreboard
{
	//this is for carrying your lives over to the other scenes
public:
	static Scoreboard* Instance()
	{
		if(instance == nullptr)
		{
			instance = new Scoreboard();
			return instance;
		}
		return instance;
	}
	int getLives();
	void setLives(int setlives);
	int getScore();
	void setScore(int setScore);
	int getHighScore();
	void setHighScore(int num);
	void resetValues();
	void addEntry(std::string name, int score);
	std::vector<PlayerEntry*> playerEntry;
	std::vector<PlayerEntry*> getPlayerEntry();
	
private:
	Scoreboard();
	~Scoreboard();
	
	int lives;
	int score;
	int highScore;
	static Scoreboard* instance;
};

#endif 