#pragma once
#include "flatfactory.h"
class OpenGLCircleFactory :
	public FlatFactory
{
public:

	FlatShape* OpenGLCircleFactory::createShape(float z);
};

