#include "BasicBody.h"
BasicBody::BasicBody(){}
BasicBody::~BasicBody(){}

void BasicBody::Damage(int i)
{
	if (parent.GetParentType == "Enemy")
	{
		parent.GetEParent()->Damage(i);
	}
	else //parent.GetParentType should always equal "Player" at this point
	{
		parent.GetPParent()->Damage(i);
	}
}
