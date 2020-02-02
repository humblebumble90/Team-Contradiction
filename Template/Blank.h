#pragma once
#ifndef __BLANK__
#define __BLANK__
#endif
#include "ShipComponent.h"
class Blank : public ShipComponent
{
public:
	Blank();
	~Blank();

/*
	Blank is a ShipComponent that is empty. Essentially, Blank is used to designate an empty spot on a Frame
	With how Frames currently work, they will always be rectangular, unless Blank is used. Blank allows Frames to be in new shapes
	e.g.:

	(player example)

	b = body
	e = blank (empty)
	w = weapon
	
		b	b	w	e
		b	b	b	w
		b	b	w	e
*/
};