#include "quad_test.h"

#include "main_application.h"
#include "base_config.h"

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W	400
#define VIEW_H	400

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
}

void main_initial_func()
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
}

void main_destroy_func()
{
}

void main_reshape_func(int w, int h)
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
}

void main_display_func()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4f(1.0F, 0.0F, 0.0F, 0.0F);
	glutSwapBuffers();
}
