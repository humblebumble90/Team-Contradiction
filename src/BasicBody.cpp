#include "BasicBody.h"
BasicBody::BasicBody(){}
BasicBody::~BasicBody(){}

void BasicBody::Damage()
{
	if (parent.GetParentType == "Enemy")
	{
		parent.GetEParent().Damage();
	}
	else //parent.GetParentType should always equal "Player" at this point
	{
		parent.GetPParent().Damage();
	}
}
