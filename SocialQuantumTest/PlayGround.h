#pragma once

#include "FlatShape.h"
#include <list>

using namespace std;

class PlayGround {
private:
	list<FlatShape*> shapes;

public:

	//Draws all shapes on the playground.
	void draw();
	//Adds new shape to the palyground.
	void addShape(FlatShape*);
	//Checks if one of active shapes was shooted.
	//If found one - returnû its score value and removes it from playground.
	//Only one shape could be shooted at once.
	int shoot(float x, float y);
	//Retuns current max z coordinate
	float getZOffset();
};

