#include "Scoreboard.h"
#include "Config.h"
#include <fstream>

Scoreboard::Scoreboard()
{
	lives = Config::LIVES;
	score = Config::SCORE;
	//learning how to do reading and writing files so ignore this
	std::ofstream scores;
	
}

Scoreboard::~Scoreboard()
{
	delete this;
}


int Scoreboard::getLives()
{
	return lives;
}

void Scoreboard::setLives(int Lives)
{
	lives = Lives;
}

int Scoreboard::getScore()
{
	return score;
}

void Scoreboard::setScore(int Score)
{
	score = Score;
}
