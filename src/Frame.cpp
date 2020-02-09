#include "Frame.h"
Frame::Frame(){/*DANGER! Do not use!*/ }
Frame::Frame(int size, std::vector<std::vector<ShipComponent>> buildLayout)
{
	gridSize = size;
	build = buildLayout;
	for (int z = 0; z < build.size; ++z) {
		for (int y = 0; y < build[z].size; ++y) {
			build[z][y].setID(z, y);
		}
	}
}
Frame::~Frame() {}

void Frame::Initialize(Enemy* parent)
{
	eParent = parent;
	parentType = "Enemy";
}

void Frame::Initialize(PlayerShip* parent)
{
	pParent = parent;
	parentType = "Player";
}

std::string Frame::GetParentType()
{
	return parentType;
}

Enemy* Frame::GetEParent()
{
	return eParent;
}

PlayerShip* Frame::GetPParent()
{
	return pParent;
}

std::vector<Weapon> Frame::GetWeapons()
{
	std::vector<Weapon> Weapons;
	for(std::vector<ShipComponent> sc : build)
	{
		for (ShipComponent s : sc)
		{
			if (typeid(s) == typeid(Weapon)) {
				ShipComponent* a = &s;
				Weapon* w = (Weapon*)a;
				Weapons.push_back(*w);
			}
		}
	}
	return Weapons;
}

Weapon Frame::GetWeapon(int i)
{
	return GetWeapons()[i];
}

int Frame::getGridSize()
{
	return gridSize;
}

int Frame::GridWidth() //Width and Height might be backwards
{
	return build[0].size;
}

int Frame::GridHeight() //Width and Height might be backwards
{
	return build.size;
}

std::vector<std::vector<ShipComponent>> Frame::GetBuild()
{
	return build;
}
