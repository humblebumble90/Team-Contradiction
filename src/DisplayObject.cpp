#include "DisplayObject.h"
#include "TextureManager.h"

Scene * DisplayObject::getParent()
{
	return m_pParentScene;
}

void DisplayObject::setParent(Scene * parent)
{
	m_pParentScene = parent;
}

//Change Texture:
//this changes the texture for the current object by using the id and sets the texture size
void DisplayObject::changeTexture(std::string idname)
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("asdasd");
	if(size.x == -1 || size.y == -1)
	{
		std::cout << "unable to get texture for id name:" << id << std::endl;
	}
	else
	{
		id = idname;
		setWidth(size.x);
		setHeight(size.y);
	}
}

void DisplayObject::Damage(int i) //Do not use!
{
}
