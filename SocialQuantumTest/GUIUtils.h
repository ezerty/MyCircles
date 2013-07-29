#pragma once

#include "OpenGLUtils.h"

// Function Declarations
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//Create a window
HWND createMainWindow ( HINSTANCE hInstance);
//Run main loop
WPARAM run ();