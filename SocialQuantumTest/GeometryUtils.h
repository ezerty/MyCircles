#pragma once
#include <stdlib.h>

namespace GeometryUtils {
	
	struct RGBColor {
		float red;
		float green;
		float blue;
	};

	extern const float SHAPE_MAX_SIZE;
	extern const float SHAPE_MIN_SIZE;
	
	extern const float BORDER_LEFT;
	extern const float BORDER_RIGHT;
	extern const float BORDER_TOP;
	extern const float BORDER_BOTTOM;
	extern const float BORDER_NEAR;
	extern const float BORDER_FAR;
	
	extern const float Z_OFFSET;

	extern const RGBColor COLOR_WHITE;
	extern const RGBColor COLOR_RED;
	extern const RGBColor COLOR_GREEN;
	extern const RGBColor COLOR_BLUE;
	extern const RGBColor COLOR_YELLOW;
	extern const RGBColor COLOR_MAGENTA;
	extern const RGBColor COLOR_CYAN;
	extern const RGBColor COLOR_BLACK;
	//Colors used by painter, background color(black) is not included.
	extern RGBColor PAINTER_COLORS[];

	//Returns random float value at certain interval
	extern float getRandom (float min, float max);
	//Returns random shape size
	extern float getRandomSize();
	//Returns random shape center x coordinate
	extern float getRandomCenterX(float size);
	//Returns random color
	extern RGBColor* getRandomColor();
}

