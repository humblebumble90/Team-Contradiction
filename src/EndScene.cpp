#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include <iomanip>
#include "Scoreboard.h"
#include "Entry_Bg.h"
#include "cpplinq.hpp"

EndScene::EndScene()
	:naming1Done(false), naming2Done(false), naming3Done(false),entryNum(0)
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
		m_game_over_bg_->draw();
		m_Label->draw();

	if(m_pEntry != nullptr &&
		m_namingLabel1 != nullptr &&
		m_namingLabel2 != nullptr &&
		m_namingLabel3 != nullptr)
	{
		m_pEntry->draw();
		m_namingLabel1->draw();
		m_namingLabel2->draw();
		m_namingLabel3->draw();
	}

	if(!entryLabels.empty())
	{
		for(auto element : entryLabels)
		{
			element->draw();
		}
	}

}

void EndScene::update()
{
}

void EndScene::clean()
{
	delete m_Label;
	delete m_game_over_bg_;
	removeAllChildren();
}

void EndScene::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_r:
				Scoreboard::Instance()->resetValues();
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_SPACE:
				if(!naming1Done)
				{
					naming1Done = true;
					//std::cout << naming1Done;
					break;
				}
				if(naming1Done && !naming2Done)
				{
					naming2Done = true;
					//std::cout << naming2Done;
					break;
				}
				if(naming1Done && naming2Done && !naming3Done)
				{
					naming3Done = true;
					generateEntry();
					generateEntrylabels();
					break;
				}
			case SDLK_UP:
				if (entryNum < 35)
				{
					entryNum++;
				}
				else
				{
					entryNum = 0;
				}
				if(!naming1Done)
				{
					m_namingLabel1->setText("" + entryArr[entryNum]);
				}
				else
				{
					if (naming1Done && !naming2Done)
					{
						m_namingLabel2->setText("" + entryArr[entryNum]);
					}
					if (naming1Done && naming2Done && !naming3Done)
					{
						m_namingLabel3->setText("" + entryArr[entryNum]);
					}
				}
				break;
			case SDLK_DOWN:
				if(entryNum > 0)
				{
					entryNum--;
				}
				else
				{
					entryNum = 35;
				}
				if (!naming1Done)
				{
					m_namingLabel1->setText("" + entryArr[entryNum]);
				}
				if (naming1Done && !naming2Done)
				{
					m_namingLabel2->setText("" + entryArr[entryNum]);
				}
				if (naming1Done && naming2Done && !naming3Done)
				{
					m_namingLabel3->setText("" + entryArr[entryNum]);
				}
			}
			break;
		default:
			break;
		}
	}
}

void EndScene::start()
{
	if(Scoreboard::Instance()->getScore() >= Scoreboard::Instance()->getHighScore())
	{
		displayEntry();
	}
	
	loadAllSounds();
	SDL_Color red = { 255, 0, 0, 255 };
	m_Label = new Label("Push R key to restart the game.", "Dock51", 40, red, 
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.9f));
	m_Label->setParent(this);
	addChild(m_Label);
	

	m_game_over_bg_ = new Game_Over_Bg();
	m_game_over_bg_->setParent(this);
	addChild(m_game_over_bg_);
	
	playSound("GameOver", 999);

}

void EndScene::loadAllSounds()
{
	loadSound("../Assets/audio/game_over.ogg", "GameOver", SOUND_MUSIC);
}

void EndScene::displayEntry()
{
	loadTexture("../Assets/textures/entry.png", "entry");
	
	SDL_Color red = { 255, 0, 0, 255 };
	
	m_namingLabel1 = new Label("A", "Consolas", 40, red,
		glm::vec2(Config::SCREEN_WIDTH * 0.425f, Config::SCREEN_HEIGHT * 0.5f));
	m_namingLabel1->setParent(this);
	addChild(m_namingLabel1);
	m_namingLabel2 = new Label("A", "Consolas", 40, red,
		glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	m_namingLabel2->setParent(this);
	addChild(m_namingLabel2);
	m_namingLabel3 = new Label("A", "Consolas", 40, red,
		glm::vec2(Config::SCREEN_WIDTH * 0.575f, Config::SCREEN_HEIGHT * 0.5f));
	m_namingLabel3->setParent(this);
	addChild(m_namingLabel3);

	m_pEntry = new Entry_Bg();
	m_pEntry->setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5f, Config::SCREEN_HEIGHT * 0.5f));
	m_pEntry->setParent(this);
	addChild(m_pEntry);

}

void EndScene::generateEntry()
{
	//std::cout << naming3Done;
	std::string entryName = "" + m_namingLabel1->getText() + "" + m_namingLabel2->getText() +
		"" + m_namingLabel3->getText();
	std::cout << entryName << std::endl;
	int score = Scoreboard::Instance()->getScore();
	std::cout << score << std::endl;
	Scoreboard::Instance()->addEntry(entryName, score);
}

void EndScene::generateEntrylabels()
{
	if (!Scoreboard::Instance()->getPlayerEntry().empty())
	{
		for (int i = 0; i < Scoreboard::Instance()->getPlayerEntry().size(); i++)
		{
			if(i < 1)
			{
				Label* playerNameLabel = new Label(Scoreboard::Instance()->getPlayerEntry()[i]->getName(),
					"Consolas", 40, black,
					glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * 0.5f));
				playerNameLabel->setParent(this);
				addChild(playerNameLabel);
				entryLabels.push_back(playerNameLabel);
				Label* playerScoreLabel
					= new Label(std::to_string(Scoreboard::Instance()->getPlayerEntry()[i]->getScore()),
						"Consolas", 40, black,
						glm::vec2(Config::SCREEN_WIDTH * 0.85f, Config::SCREEN_HEIGHT * 0.5f));
				playerScoreLabel->setParent(this);
				addChild(playerScoreLabel);
				entryLabels.push_back(playerScoreLabel);
			}
			else
			{
				Label* playerNameLabel = new Label(Scoreboard::Instance()->getPlayerEntry()[i]->getName(),
					"Consolas", 40, black,
					glm::vec2(Config::SCREEN_WIDTH * 0.75f, Config::SCREEN_HEIGHT * (0.5f + i*0.05f)));
				playerNameLabel->setParent(this);
				addChild(playerNameLabel);
				entryLabels.push_back(playerNameLabel);
				Label* playerScoreLabel
					= new Label(std::to_string(Scoreboard::Instance()->getPlayerEntry()[i]->getScore()),
						"Consolas", 40, black,
						glm::vec2(Config::SCREEN_WIDTH * 0.85f, Config::SCREEN_HEIGHT * (0.5f + i * 0.05f)));
				playerScoreLabel->setParent(this);
				addChild(playerScoreLabel);
				entryLabels.push_back(playerScoreLabel);
			}
		}
	}
}
