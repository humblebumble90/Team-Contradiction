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
	TheTextureManager::Instance()->load(path,
		id, TheGame::Instance()->getRenderer());
	std::cout << "texture set with path: " << path << std::endl;
	std::cout << "^id: " << id << std::endl;
}

void Scene::loadSound(std::string path, std::string id, sound_type type)
{
	TheSoundManager::Instance()->load(path, id, type);
	std::cout << "sound set with path: " << path << std::endl;
	std::cout << "^id: " << id << std::endl;
}
