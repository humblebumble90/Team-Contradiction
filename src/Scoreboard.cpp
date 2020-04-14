#include "Scoreboard.h"
#include "Config.h"
#include <fstream> //learning how to do reading and writing files so ignore this
#include <iostream>
#include <string>
#include <vector>
#include "PlayerShip.h"
#include "PlayerEntry.h"
#include <algorithm>
#include "cpplinq.hpp"
#include "Game.h"

Scoreboard* Scoreboard::instance = nullptr;

std::vector<PlayerEntry*> Scoreboard::getPlayerEntry()
{
	auto result = cpplinq::from_iterators(playerEntry.begin(), playerEntry.end())
		>> cpplinq::orderby_descending([](PlayerEntry* const& p) {return p->getScore(); })
		>> cpplinq::thenby([](PlayerEntry* p) {return p->getName(); })
		>> cpplinq::to_vector();
	return result;
}

Scoreboard::Scoreboard()
{
	highScore = Config::HIGH_SCORE;
}

Scoreboard::~Scoreboard()
{
	delete this;
}

void Scoreboard::resetValues()
{
	lives = Config::LIVES;
	score = Config::SCORE;
	TheGame::Instance()->resetContinues();

}

void Scoreboard::addEntry(std::string name, int score)
{
	PlayerEntry* player = new PlayerEntry(name, score);
	playerEntry.push_back(player);
	//PlayerEntry* exPlayer1 = new PlayerEntry("B", 1500);
	//PlayerEntry* exPlayer2 = new PlayerEntry("C", 1600);
	//PlayerEntry* exPlayer3 = new PlayerEntry("D", 1700);
	//PlayerEntry* exPlayer4 = new PlayerEntry("E", 1800);
	//PlayerEntry* exPlayer5 = new PlayerEntry("F", 1900);
	//PlayerEntry* exPlayer6 = new PlayerEntry("G", 2000);
	//PlayerEntry* exPlayer7 = new PlayerEntry("H", 2200);
	//PlayerEntry* exPlayer8 = new PlayerEntry("I", 2200);
	//playerEntry.push_back(exPlayer1);
	//playerEntry.push_back(exPlayer2);
	//playerEntry.push_back(exPlayer3);
	//playerEntry.push_back(exPlayer4);
	//playerEntry.push_back(exPlayer5);
	//playerEntry.push_back(exPlayer6);
	//playerEntry.push_back(exPlayer7);
	//playerEntry.push_back(exPlayer8);
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
