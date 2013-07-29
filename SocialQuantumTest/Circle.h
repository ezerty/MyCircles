#pragma once

#include "flatshape.h"

class Circle :
	public FlatShape
{
public:
	Circle(float x, float y, float z, float overallSize, GeometryUtils::RGBColor* color);

	//Checks if the specified point covered with circle.
	virtual bool covers(float x, float y);
	//Returns bottomost ponts Y coordinate.
	virtual float getBottommostCoordinate();
	//Returns circle radius.
	float getRadius();
};

