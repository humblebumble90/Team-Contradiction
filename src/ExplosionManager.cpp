#include "ExplosionManager.h"
#include "TextureManager.h"

ExplosionManager* ExplosionManager::s_pInstance = nullptr;



ExplosionManager::ExplosionManager() :m_explosionNumber(10)
{
	m_buildExplosionPool();
}

ExplosionManager::~ExplosionManager()
= default;

void ExplosionManager::m_buildExplosionPool()
{
	m_pExplosionPool = std::list<Explosion*>();

	for (int i = 0; i < m_explosionNumber; i++)
	{
		m_pExplosionPool.push_back(new Explosion());
	}
}

void ExplosionManager::clean()
{
}

Explosion* ExplosionManager::getExplosion()
{
	Explosion* explosion = m_pExplosionPool.front();
	m_pExplosionPool.pop_front();
	m_pExplosionPool.push_back(explosion);
	return explosion;
}

void ExplosionManager::update()
{
	for (auto explosion : m_pExplosionPool)
		if (explosion->getIsActive())
		{
			explosion->update();
		}
}

void ExplosionManager::draw()
{
	for (auto explosion : m_pExplosionPool)
	{
		if (explosion->getIsActive())
		{
			explosion->draw();
		}
	}
}
