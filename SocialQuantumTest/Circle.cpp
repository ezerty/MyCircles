#include <math.h>
#include "Circle.h"

Circle::Circle(float x, float y, float z, float overallSize, GeometryUtils::RGBColor* color) 
	: FlatShape(x, y, z, overallSize, color) {
}


bool Circle::covers(float x, float y) {
	return sqrt(pow(getX() - x, 2) + pow(getY() - y, 2)) <  getRadius();
}

float Circle::getBottommostCoordinate() {
	return getY() - getRadius();
}

float Circle::getRadius() {
	return getOverallSize();
}