#include "FlatShape.h"
#include "GeometryUtils.h"

FlatShape::FlatShape(float x, float y, float z, float overallSize, GeometryUtils::RGBColor* color) {
	if(overallSize > GeometryUtils::SHAPE_MAX_SIZE) {
		overallSize = GeometryUtils::SHAPE_MAX_SIZE;
	} else if (overallSize < GeometryUtils::SHAPE_MIN_SIZE) {
		overallSize = GeometryUtils::SHAPE_MIN_SIZE;
	}
	this->x = x;
	this->y = y;
	this->z = z;
	this->overallSize = overallSize;
	this->speed = .0f;
	this->color = color;
}

FlatShape::~FlatShape() {
}

float FlatShape::getX() {
	return x;
}

float FlatShape::getY() {
	return y;
}

float FlatShape::getZ() {
	return z;
}

float FlatShape::getOverallSize() {
	return overallSize;
}

void FlatShape::setX(float x) {
	this->x = x;
}

void FlatShape::setY(float y) {
	this->y = y;
}

void FlatShape::setZ(float z) {
	this->z = z;
}

void FlatShape::setOverallSize(float overallSize) {
	this->overallSize = overallSize;
}

float FlatShape::calculateSpeed() {
	return (GeometryUtils::SHAPE_MAX_SIZE  + GeometryUtils::SHAPE_MIN_SIZE - overallSize) / 30;
}

float FlatShape::getSpeed() {
	if(speed == .0f) {
		speed = calculateSpeed();
	}
	return speed;
}

int FlatShape::getScore() {
	return (int) 1 / overallSize;
}

void FlatShape::moveDown() {
	setY( getY() - getSpeed());
}

GeometryUtils::RGBColor* FlatShape::getColor() {
	return color;
}