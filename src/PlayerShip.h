#pragma once
#ifndef __PlayerShip__
#define __PlayerShip__

#include "GameObject.h"
#include "TextureManager.h"

class PlayerShip : public GameObject {
public:
	PlayerShip();
	~PlayerShip();

	//Initialization
	void Start();

	glm::vec2 getPlayerMaxSpeedX();
	glm::vec2 maxSpeedX;
	glm::vec2 getPlayerminSpeedX();
	glm::vec2 minSpeedX;
	glm::vec2 getPlayerMaxSpeedY();
	glm::vec2 maxSpeedY;
	glm::vec2 getPlayerMinSpeedY();
	glm::vec2 minSpeedY;

	// Draw the object
	void draw() override;

	// Update the object
	void update() override;

	// remove anything that needs to be deleted
	void clean() override;

	void Damage(int i);
private:

};


#endif /* defined (__PlayerShip__) */