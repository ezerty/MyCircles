#pragma once

#include "FlatShape.h"

//Abstract shape factory.
class FlatFactory
{
public:
	//Create a shape
	virtual FlatShape* createShape(float z) = 0;
};

