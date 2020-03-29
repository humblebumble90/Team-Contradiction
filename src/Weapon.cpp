#include "Weapon.h"
#include "MissileLauncher.h"
#include "Cannon.h"
#include "Flamethrower.h"

Weapon::Weapon()
{


}

Weapon::~Weapon()
{

}

void Weapon::Fire()
{
	if (name == "MissileLauncher"){
		((MissileLauncher*)this)->Fire();
	}
	else if (name == "Cannon") {
		((Cannon*)this)->Fire();
	}
	else if (name == "Flamethrower")
	{
		((Flamethrower*)this)->Fire();
	}
	std::cout << "Fired " << name << " Weapon" << std::endl;
}
