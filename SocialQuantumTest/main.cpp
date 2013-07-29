#include "GUIUtils.h"
#include <time.h>

int main(int argc, char* argv[] ) {
	srand((unsigned)time(0));
	HINSTANCE hInstance = GetModuleHandle(NULL);
	WinMain(hInstance, hInstance, "", 0);
	return 0;
}