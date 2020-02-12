#include "Frame.h"
#include "Weapon.h"
Frame::Frame(){/*DANGER! Do not use!*/ }
Frame::Frame(int size, std::vector<ShipComponent> buildLayout, int width, int height)
{
	gridWidth = width;
	gridHeight = height;
	gridSize = size;
	build = buildLayout;
	for (int z = 0; z < gridWidth; ++z) {
		for (int y = 0; y < build.size(); y+=gridWidth) {
			build[y].setID(z, (y-z)/gridWidth);
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
	for (ShipComponent s : build)
	{
		if (typeid(s) == typeid(Weapon)) {
			Weapons.push_back(*(Weapon*)& s);
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
	return gridWidth;
}

int Frame::GridHeight() //Width and Height might be backwards
{
	return gridHeight;
}

std::vector<ShipComponent> Frame::GetBuild()
{
	return build;
}
