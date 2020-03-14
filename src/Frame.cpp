#include "Frame.h"
#include "Weapon.h"
Frame::Frame() = default;//DANGER! Do not use!

Frame::Frame(int size, std::vector<ShipComponent>& buildLayout, int width, int height)
: gridWidth(width), gridHeight(height), gridSize(size), build(buildLayout)
{
	for (int z = 0; z < gridWidth; ++z) {
		for (int y = z; y < build.size(); y += gridWidth) {
			build[y].setID(glm::vec2(z, (y - z) / gridWidth));
			build[y].setParent(this);
		}
	}
}

Frame::~Frame() {}

void Frame::Initialize(DisplayObject* Parent)
{
	parent = Parent;
}

DisplayObject* Frame::getParent()
{
	return parent;
}

std::vector<Weapon> Frame::GetWeapons()
{
	std::vector<Weapon> Weapons;
	for (ShipComponent s : build)
	{
		//ShipComponent* m_s = &s;
		if (s.getName()=="Flamethrower" || s.getName() == "Cannon" || s.getName() == "MissileLauncher") {
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
