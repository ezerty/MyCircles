#pragma once

#include "OpenGLUtils.h"
#include "circle.h"

class OpenGLCircle :
	public Circle
{
protected:
	//Quadric singleton getter.
	GLUquadric* getQuadric();

public:
	OpenGLCircle(float x, float y, float z, float overallSize, GeometryUtils::RGBColor *color);

	//Draws OpenGL circle with specified center and radius.
	virtual void draw();
	
	virtual bool covers(float x, float y);
};

