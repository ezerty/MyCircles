#pragma once

#include "GeometryUtils.h"

// Mostly general abstract shape class, defines basic properties for all game objects.
class FlatShape {

private:
	//Shape center coordinates in synthetic orthogonal system.
	//Center of playground is (0,0,0), linear borders are (-1; 1).
	//z-coordinate used to determine which circle is covers other on intersections:
	//the next circles covers previous ones.
	float x, y, z;
	//Movement speed bufferred value.
	float speed;
	//Distance between shape center and the outermost vertex.
	float overallSize;
	GeometryUtils::RGBColor *color;
protected:

	//Actually calculates movement speed by size, used in getSpeed method.
	//Override this for a specific speed calculation.
	//Do not use this for access the speed field, use getSpeed instead.
	virtual float calculateSpeed();
	//Returns actual speed value.
	virtual float getSpeed();

	void setX(float);
	void setY(float);
	void setZ(float);
	void setOverallSize(float);

public:
	FlatShape(float x, float y, float z, float overallSize, GeometryUtils::RGBColor* color);
	~FlatShape(void);

	//Returns score, calculated with size at shape specific way.
	virtual int getScore();
	//Moves shape down.
	virtual void moveDown();

	//Checks if shape covers specified point.
	virtual bool covers(float x, float y) = 0;
	//Draws this shape.
	virtual void draw() = 0;
	//Returns the bottommost Y coordinate of shape.
	virtual float getBottommostCoordinate() = 0;

	float getX();
	float getY();
	float getZ();
	float getOverallSize();
	//Returns RGB color, where each color value is float in (0.f;1.f) interval
	GeometryUtils::RGBColor* getColor();

};

