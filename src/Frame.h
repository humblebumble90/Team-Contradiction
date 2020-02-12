#pragma once
#ifndef __FRAME__
#define __FRAME__
#include "DisplayObject.h"
class Frame {
public:
	friend class Enemy;
	friend class PlayerShip;
	friend class ShipComponent;
	friend class Weapon;
	Frame();
	Frame(int size, std::vector<ShipComponent> buildLayout, int width, int height);
	~Frame();
	void Initialize(Enemy* parent);
	void Initialize(PlayerShip* parent);
	std::string GetParentType();
	Enemy* GetEParent();
	PlayerShip* GetPParent();
	std::vector<Weapon> GetWeapons();
	Weapon GetWeapon(int i);
	int getGridSize(), GridWidth(), GridHeight();
	std::vector<ShipComponent> GetBuild();
private:
	int gridSize, gridWidth, gridHeight;
	std::vector<ShipComponent> build = std::vector<ShipComponent>();
	Enemy* eParent;
	PlayerShip* pParent;
	std::string parentType;
};
#endif