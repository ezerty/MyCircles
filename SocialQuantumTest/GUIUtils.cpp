#include "GUIUtils.h"
#include "PlayGround.h"
#include "OpenGLCircleFactory.h"
#include <vector>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;

void draw ();

HDC hDC;
OpenGLCircleFactory circleFactory;
PlayGround palyground;

int score = 0;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine, int iCmdShow) {
	HGLRC hRC;

	HWND hWnd = createMainWindow ( hInstance);

	startupOpenGL( hWnd, &hDC, &hRC);
	// program main loop
	run ();

	cleanupOpenGL( hWnd, hDC, hRC );

	// destroy the window explicitly
	DestroyWindow( hWnd );

	return 0;
}

WPARAM run() {
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	//Loop while not get quit message.
	while( msg.message != WM_QUIT)
	{
		//read message
		if(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			draw();
		}
	}
	return msg.wParam;
}


LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message)
	{

	case WM_CREATE:
		{
			return 0;
		}

	case WM_CLOSE:
		{
			//Break message loop
			PostQuitMessage( 0);
			return 0;
		}
	case WM_DESTROY:
		{
			return 0;
		}

	case WM_LBUTTONDOWN:
		{
			LPARAM cursorCoordinates = GetMessagePos();
			RECT windowRect;
			GetWindowRect (hWnd, &windowRect);

			vector<GLdouble> glPos = 
				getGLPos(GET_X_LPARAM(cursorCoordinates) - windowRect.left - GetSystemMetrics(SM_CXFRAME) / 2, 
				GET_Y_LPARAM(cursorCoordinates) - windowRect.top - GetSystemMetrics(SM_CYCAPTION));
			
			score += palyground.shoot(glPos[0], glPos[1]);

			return 0;
		}

	default:
		//Reroute to default handler
		return DefWindowProc( hWnd, message, wParam, lParam );

	}

}

HWND createMainWindow( HINSTANCE hInstance) {
	WNDCLASS wc;
	HWND hWnd;

	// register window class
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_APPLICATION );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW );
	wc.hbrBackground = (HBRUSH)GetStockObject( BLACK_BRUSH );
	wc.lpszMenuName = NULL;
	wc.lpszClassName = "MyCircles";
	RegisterClass( &wc );

	// create main window
	hWnd = CreateWindow( 
		"MyCircles", "Circles", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE,
		50, 50, 800, 600,
		NULL, NULL, hInstance, NULL );
	return hWnd;
}


time_t lastShapeCreateion = time(0);

void draw () {
	
	time_t currentTime = time(0);
	if(difftime(currentTime, lastShapeCreateion) > 0) {
		for (int i = 0; i < 3; i++) {
			palyground.addShape(circleFactory.createShape(palyground.getZOffset()));
		}
		lastShapeCreateion = currentTime;
	}
	
	clearScreen();
	palyground.draw();
	stringstream str;
	str << "Score: " << score;
	printText(str.str());
	SwapBuffers( hDC );

}
