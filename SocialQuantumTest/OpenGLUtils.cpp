#include "OpenGLUtils.h"
#include "GeometryUtils.h"

float aspect = 1.f;

void startupOpenGL( HWND hWnd, HDC * hDC, HGLRC * hRC, BOOL VSync) {
	PIXELFORMATDESCRIPTOR pfd;
	int format;

	*hDC = GetDC( hWnd );

	//Build pixel format
	ZeroMemory( &pfd, sizeof( pfd ) );
	pfd.nSize = sizeof( pfd );
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;    
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 8;
	format = ChoosePixelFormat( *hDC, &pfd );
	SetPixelFormat( *hDC, format, &pfd );

	// create and enable the render context (RC)
	*hRC = wglCreateContext( *hDC );
	wglMakeCurrent( *hDC, *hRC );

	const char *extensions = reinterpret_cast< const char*>( glGetString( GL_EXTENSIONS ));

	if( strstr( extensions, ("WGL_EXT_swap_control") ) == 0 )
		return; // Error: WGL_EXT_swap_control extension not supported on your computer.\n");
	else
	{
		BOOL (APIENTRY *wglSwapIntervalEXT)( int ) = 
			reinterpret_cast< BOOL (APIENTRY *)(int)>( wglGetProcAddress( "wglSwapIntervalEXT" ));
		if( wglSwapIntervalEXT )
			wglSwapIntervalEXT( VSync);
	}   
	
	//Prepare bitmap for text printing
	wglUseFontBitmaps(*hDC, 0, 256, 1000);
	glListBase(1000);

	//Configure projection matrix to use current aspect ratio
	GLint viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );
	int width = viewport[2];
	int height = viewport[3];
	glMatrixMode(GL_PROJECTION);
	aspect = (float)width / (float)height;
	glOrtho(-aspect, aspect, 
		GeometryUtils::BORDER_BOTTOM, 
		GeometryUtils::BORDER_TOP, 
		GeometryUtils::BORDER_NEAR, 
		GeometryUtils::BORDER_FAR);

	glMatrixMode(GL_MODELVIEW);
	glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
	glLoadIdentity();

}

void cleanupOpenGL( HWND hWnd, HDC hDC, HGLRC hRC) {
	glDeleteLists(1000, 256) ; 
	wglMakeCurrent( NULL, NULL );
	wglDeleteContext( hRC );
	ReleaseDC( hWnd, hDC );
}

vector<GLdouble> getGLPos(int x, int y) {
	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
	glGetDoublev( GL_PROJECTION_MATRIX, projection );
	glGetIntegerv( GL_VIEWPORT, viewport );

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );

	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	vector<GLdouble> vector;
	vector.push_back(posX);
	vector.push_back(posY);
	vector.push_back(posZ);

	return vector;
}

void printText(string text) {
	glColor3f( 1.0f, 1.0f, 1.0f );
	glRasterPos2f(-0.95f * aspect, -0.95f);
	glCallLists(text.length(), GL_UNSIGNED_BYTE, text.c_str());
	glFlush(); 

}

void clearScreen() {
	glClear( GL_COLOR_BUFFER_BIT );
}