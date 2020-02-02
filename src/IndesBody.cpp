#include "IndesBody.h"

IndesBody::IndesBody(bool projectile)
{
	isProjectile = projectile;
}
IndesBody::~IndesBody(){}
void IndesBody::Damage(ShipComponent* collision)
{
	if (isProjectile)
	{
		try
		{
			IndesBody* indesCol = (IndesBody*) collision;
			if (indesCol->isProjectile)
			{
				return;
			}
		}
		catch (_exception){}
		//Destroy this object
	}
}
