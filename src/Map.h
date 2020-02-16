#pragma once
#ifndef __MAP__
#define __MAP__

#include "GameObject.h"
#include "TextureManager.h"

class Map : public GameObject {
public:
	// Constructor / Destructor
	Map();
	~Map();

	// Inherited via GameObject
	void draw() override;
	void update() override;
	void clean() override;
private:
	void _move();
	void _checkBounds();
	void _reset();
};

#endif // defined (__MAP__)
#pragma once
