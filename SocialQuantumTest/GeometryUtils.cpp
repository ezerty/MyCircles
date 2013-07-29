#include "GeometryUtils.h"

using namespace GeometryUtils;

const float GeometryUtils::SHAPE_MIN_SIZE = .05f;
const float GeometryUtils::SHAPE_MAX_SIZE = .2f;

const float GeometryUtils::BORDER_LEFT = -1.f;
const float GeometryUtils::BORDER_RIGHT = 1.f;
const float GeometryUtils::BORDER_TOP = 1.f;
const float GeometryUtils::BORDER_BOTTOM = -1.f;
const float GeometryUtils::BORDER_NEAR = 1.f;
const float GeometryUtils::BORDER_FAR = -1.f;

const RGBColor GeometryUtils::COLOR_WHITE = {1.f, 1.f, 1.f};
const RGBColor GeometryUtils::COLOR_RED = {1.f, 0.f, 0.f};
const RGBColor GeometryUtils::COLOR_GREEN = {0.f, 1.f, 0.f};
const RGBColor GeometryUtils::COLOR_BLUE = {0.f, 0.f, 1.f};
const RGBColor GeometryUtils::COLOR_CYAN = {0.f, 1.f, 1.f};
const RGBColor GeometryUtils::COLOR_MAGENTA = {1.f, 0.f, 1.f};
const RGBColor GeometryUtils::COLOR_YELLOW = {1.f, 1.f, 0.f};
const RGBColor GeometryUtils::COLOR_BLACK = {0.f, 0.f, 0.f};

RGBColor GeometryUtils::PAINTER_COLORS[] = {COLOR_WHITE, 
	COLOR_RED, COLOR_GREEN, COLOR_BLUE, COLOR_CYAN, 
	COLOR_MAGENTA, COLOR_YELLOW};


const float GeometryUtils::Z_OFFSET = .0001f;

float GeometryUtils::getRandom(float min, float max) {
	return min + (float)rand()/((float)RAND_MAX/(max-min));
}

float GeometryUtils::getRandomCenterX(float size) {
	return getRandom(BORDER_LEFT + size, BORDER_RIGHT - size);
}

float GeometryUtils::getRandomSize() {
	return getRandom(SHAPE_MIN_SIZE, SHAPE_MAX_SIZE);
}

RGBColor* GeometryUtils::getRandomColor() {
	int randomIndex = rand() % sizeof(PAINTER_COLORS) / sizeof(RGBColor);
	return &PAINTER_COLORS[randomIndex];
}