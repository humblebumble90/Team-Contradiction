#include "Cannon.h"

Cannon::Cannon()
{
	name = "Cannon";
}

Cannon::~Cannon()
{
}

void Cannon::Fire()
{
}
void Cannon::Fire(glm::vec2 direction) {
	//this method is the same as Fire(), however, the projectile will travel in the specified direction
	//e.g.	0,0 will not travel
	//		0,1 will travel down
	//		-1,0 will travel left
	//		etc.
}
