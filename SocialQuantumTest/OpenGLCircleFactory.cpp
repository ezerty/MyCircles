#include "OpenGLCircleFactory.h"
#include "OpenGLCircle.h"
#include "GeometryUtils.h"

using namespace GeometryUtils;

FlatShape* OpenGLCircleFactory::createShape(float z) {

	float size = getRandomSize();
	return new OpenGLCircle(getRandomCenterX(size), BORDER_TOP - size, z + Z_OFFSET, size, getRandomColor());
	
}

float getRandom (float min, float max) {
	return min + (float)rand()/((float)RAND_MAX/(max-min));
}
