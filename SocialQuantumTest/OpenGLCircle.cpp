#include "OpenGLCircle.h"

OpenGLCircle::OpenGLCircle(float x, float y, float z, float overallSize, GeometryUtils::RGBColor *color)
	: Circle(x, y, z, overallSize, color) {
}

GLUquadric* OpenGLCircle::getQuadric() {
		static GLUquadric *quadric;
		if(quadric == 0) {
			quadric = gluNewQuadric();
		}
		return quadric;
	}

void OpenGLCircle::draw() {
	
	GeometryUtils::RGBColor* color = getColor();
	glPushMatrix();
		glColor3f( color->red, color->green, color->blue );
		//Correct horizontal position by aspect ratio 
		glTranslatef(getX() * aspect, getY(), getZ());
		gluDisk(getQuadric(), 0.f, getOverallSize() * aspect, 20, 1);
	glPopMatrix();	
}

bool OpenGLCircle::covers(float x, float y) {
	//Correct horizontal position by aspect ratio 
	return Circle::covers(x / aspect, y);
}