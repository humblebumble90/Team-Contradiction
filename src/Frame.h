#pragma once
#ifndef __FRAME__
#define __FRAME__
#include "PlayerShip.h"
#include "Enemy.h"
class Frame {
public:
	Frame();
	Frame(int size, std::vector<std::vector<ShipComponent>> buildLayout);
	~Frame();
	void Initialize(Enemy* parent);
	void Initialize(PlayerShip* parent);
	std::string GetParentType();
	Enemy* GetEParent();
	PlayerShip* GetPParent();
	std::vector<Weapon> GetWeapons();
	Weapon GetWeapon(int i);
	int getGridSize(), GridWidth(), GridHeight();
	std::vector<std::vector<ShipComponent>> GetBuild();
private:
	int gridSize;
	std::vector<std::vector<ShipComponent>> build;
	Enemy* eParent;
	PlayerShip* pParent;
	std::string parentType;
};
#endif