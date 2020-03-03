#include "IndesBody.h"
#include "Game.h"

IndesBody::IndesBody(bool projectile)
{
	isProjectile = projectile;
	name = "IndesBody";
}
IndesBody::~IndesBody(){}
void IndesBody::Damage(ShipComponent collision)
{
	if (isProjectile)
	{
		try
		{
			IndesBody indesCol = (IndesBody) &collision;
			if (indesCol.isProjectile)
			{
				return;
			}
		}
		catch (_exception){}
		Game::Instance()->destroyEnemy((Enemy*)getParent()->getParent());
	}
}
