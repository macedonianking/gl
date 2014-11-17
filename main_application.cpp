#include "main_application.h"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define VIEW_W	400	
#define VIEW_H	200

static void main_diaplay_func();
static void main_reshape_func(int w, int h);
static void main_initial_func();

static bool gInitialized = false;
static main_entry_t gMainEntry;

struct main_entry_t *GetMainEntry()
{
	if (!gInitialized)
	{
		gMainEntry.mGLUTMode = GLUT_RGBA | GLUT_SINGLE;
		gMainEntry.mWindowPointX = 100;
		gMainEntry.mWindowPointY = 100;
		gMainEntry.mWindowSizeX = VIEW_W;
		gMainEntry.mWindowSizeY = VIEW_H;		
		gMainEntry.mWindowTitle = "GLWindow";
		gMainEntry.mInitialFunc = main_initial_func;
		gMainEntry.mReshapeFunc = main_reshape_func;
		gMainEntry.mDisplayFunc = main_diaplay_func;
	}	
	return &gMainEntry;
}

void main_initial_func()
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, VIEW_W, 0, VIEW_H);
}

void main_diaplay_func()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1.0F, 0.0F, 0.0F);
	glBegin(GL_LINES);
		glVertex2d(180.0, 10.0);
		glVertex2d(10.0, 180.0);
	glEnd();
	
	glFlush();
}

void main_reshape_func(int w, int h)
{
}
