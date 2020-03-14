#pragma once
#ifndef __SCOREBOARD__
#define __SCOREBOARD__

class Scoreboard
{
	//this is for carrying your lives over to the other scenes
public:
	Scoreboard* Instance()
	{
		if(instance != nullptr)
		{
			return instance;
		}
		instance = new Scoreboard();
		return instance;
	}
	int getLives();
	void setLives(int setlives);
	int getScore();
	void setScore(int setScore);
	
private:
	Scoreboard();
	~Scoreboard();
	
	int lives;
	int score;
	Scoreboard* instance;
};

#endif 