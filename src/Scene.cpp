#include "Scene.h"
#include "Game.h"

Scene::Scene()
{

}

Scene::~Scene()
{
}


void Scene::addChild(DisplayObject * child)
{
	m_displayList.push_back(child);
}

void Scene::removeAllChildren()
{
	for(auto child : m_displayList)
	{
		child = NULL;
	}
	m_displayList.clear();
	m_displayList.resize(0);
	m_displayList.shrink_to_fit();
}


int Scene::numberOfChildren()
{
	return m_displayList.size();
}

//Load Texture:
//loads the texture so that you dont need to do it in the display object
void Scene::loadTexture(std::string path, std::string id)
{
	const bool loadSucessful = TheTextureManager::Instance()->load(path,
		id, TheGame::Instance()->getRenderer());
	if (loadSucessful == true)
	{
		std::cout << "texture loaded with path: " << path << std::endl;
		std::cout << "^id: " << id << std::endl;
	}
	else
	{
		std::cout << "unable to load texture with path:" << path << std::endl;
	}

}

void Scene::loadSound(std::string path, std::string id, sound_type type)
{
	bool loadSucessful = TheSoundManager::Instance()->load(path, id, type);
	if (loadSucessful == true)
	{
		std::cout << "sound loaded with path: " << path << std::endl;
		std::cout << "^id: " << id << std::endl;
	}
	else
	{
		std::cout << "unable to load sound with path: " << path << std::endl;
	}
}

void Scene::playSound(std::string id, int loop)
{
	if (id == "Explosion") {
		TheSoundManager::Instance()->playSound(id, loop);
	}
	else {
		TheSoundManager::Instance()->playMusic(id, loop);
	}
	std::cout << "Attempted to play sound with id: " << id << std::endl;
}