#include "Scoreboard.h"
#include "Config.h"
#include <fstream> //learning how to do reading and writing files so ignore this
#include <iostream>
#include <string>
#include <vector>
#include "PlayerShip.h"
#include "PlayerEntry.h"

Scoreboard* Scoreboard::instance = nullptr;

std::vector<PlayerEntry*> Scoreboard::getPlayerEntry()
{
	return playerEntry;
}

Scoreboard::Scoreboard()
{
	highScore = Config::HIGH_SCORE;
	resetValues();
}

Scoreboard::~Scoreboard()
{
	delete this;
}

void Scoreboard::resetValues()
{
	lives = Config::LIVES;
	score = Config::SCORE;

}

void Scoreboard::addEntry(std::string name, int score)
{
	PlayerEntry* player = new PlayerEntry(name, score);
	playerEntry.push_back(player);
	//for (auto element : playerEntry)
	//{
	//	std::cout << "Name: " + element->getName() << std::endl;
	//	std::cout << "Score: " + std::to_string(element->getScore()) << std::endl;
	//}
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
	std::cout << "Current score: " + std::to_string(score) << std::endl;
	if(score >= highScore)
	{
		setHighScore(score);
	}
}

int Scoreboard::getHighScore()
{
	return highScore;
}

void Scoreboard::setHighScore(int num)
{
	std::cout << "Current HighScore: " + std::to_string(highScore)<<std::endl;
	highScore = num;
}
