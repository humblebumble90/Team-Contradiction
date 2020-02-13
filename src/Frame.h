#pragma once
#ifndef __FRAME__
#define __FRAME__
#include <vector>
#include "DisplayObject.h"
class Frame {
public:
	friend class ShipComponent; //was not part of prof's code (then again, he never got as far as adding weapon)
	friend class Weapon;
	Frame();
	Frame(int size, std::vector<ShipComponent>& buildLayout, int width, int height);
	~Frame();
	void Initialize(DisplayObject* Parent);
	DisplayObject* getParent();
	std::vector<Weapon> GetWeapons();
	Weapon GetWeapon(int i);
	int getGridSize(), GridWidth(), GridHeight();
	std::vector<ShipComponent> GetBuild();
private:
	int gridSize, gridWidth, gridHeight;
	std::vector<ShipComponent> build;
	DisplayObject* parent;
};
#endif