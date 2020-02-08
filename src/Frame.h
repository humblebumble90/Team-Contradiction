#pragma once
#ifndef __FRAME__
#define __FRAME__
#endif
#include "ShipComponent.h"
#include <vector>
#include "Enemy.h"
#include "Player.h"
class Frame {
public:
	Frame();
	Frame(int size, std::vector<std::vector<ShipComponent>> buildLayout);
	~Frame();
	void Initialize(Enemy* parent);
	void Initialize(Player* parent);
	std::string GetParentType();
	Enemy* GetEParent();
	Player* GetPParent();
	std::vector<Weapon> GetWeapons();
	Weapon GetWeapon(int i);
	int getGridSize(), GridWidth(), GridHeight();
	std::vector<std::vector<ShipComponent>> GetBuild();
private:
	int gridSize;
	std::vector<std::vector<ShipComponent>> build;
	Enemy* eParent;
	Player* pParent;
	std::string parentType;
};