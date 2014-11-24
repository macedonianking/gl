#include "quad_test.h"

#include <iostream>

#include "main_application.h"
#include "base_config.h"
#include "cube.h"
#include "wc_rect.h"
#include "wc_eclipse.h"
#include "wc_line.h"
#include "wc_fill.h"

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W	200	
#define VIEW_H	400

int					gWindowW;
int					gWindowH;
struct wc_cube_t	gCube;
struct wcRectF		gRect;
struct wcEclipse	gEclipse;

static GLuint		gWindowSizeX;
static GLuint		gWindowSizeY;

void QuadTestInitialize()
{
	struct main_entry_t *ptr;

	ptr = &gMainEntry;
	ptr->mGLUTMode = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
	ptr->mWindowTitle = "GLUTCubeTest";
	ptr->mWindowPointX = 300;
	ptr->mWindowPointY = 300;
	ptr->mWindowSizeX = VIEW_W;
	ptr->mWindowSizeY = VIEW_H;
	ptr->mDisplayFunc = main_display_func;
	ptr->mReshapeFunc = main_reshape_func;
	ptr->mInitialFunc = main_initial_func;
	ptr->mDestroyFunc = main_destroy_func;
	
	SetMainEntry(ptr);
	gWindowW = VIEW_W;
	gWindowH = VIEW_H;
}

void main_initial_func()
{
	wcPt3f origin;

	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);

	cube_initialize(&gCube,  100);
}

void main_destroy_func()
{
}

void main_reshape_func(int w, int h)
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);

	gWindowSizeX = w;
	gWindowSizeY = h;
	
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

void main_display_func()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor4f(1.0F, 0.0F, 0.0F, 0.0F);
	glClear(GL_COLOR_BUFFER_BIT);

	wcFillDraw();

	glutSwapBuffers();
}
