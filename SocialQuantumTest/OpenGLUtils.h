#pragma once

#include <Windows.h>
#include <WindowsX.h>
#pragma comment(lib, "Opengl32.lib")
#pragma comment(lib, "glu32.lib")

#include <gl\GL.h>
#include <gl\GLU.h>
#include <vector>

using namespace std;

extern float aspect;

//Setup OpenGL environment
void startupOpenGL( HWND hWnd, HDC * hDC, HGLRC * hRC, BOOL VSync =TRUE);
//Delete OpenGL environment
void cleanupOpenGL( HWND hWnd, HDC hDC, HGLRC hRC);
//Translates cursor position from window coordinates to abstract coorinate system
vector<GLdouble> getGLPos(int x, int y);
//Prints specified test at lower left
void printText(string);
//Cleanup scene before next frame rendering
void clearScreen();