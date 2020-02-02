#include "Frame.h"
Frame::Frame(){/*DANGER! Do not use!*/ }
Frame::Frame(int size, std::vector<std::vector<ShipComponent>> buildLayout)
{
	gridSize = size;
	build = buildLayout;
}
Frame::~Frame() {}

void Frame::Initialize(Enemy* parent)
{
	eParent = parent;
	parentType = "Enemy";
}

void Frame::Initialize(Player* parent)
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

Player* Frame::GetPParent()
{
	return pParent;
}

std::vector<Weapon> Frame::GetWeapons()
{
	std::vector<Weapon> Weapons;
	for(std::vector<ShipComponent> sc : build)
	{
		for (Weapon w : sc)
		{
			Weapons.push_back(w);
		}
	}
	return Weapons;
}
