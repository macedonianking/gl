#include "quad_test.h"

#include "main_application.h"
#include "base_config.h"
#include "cube.h"
#include "wc_rect.h"
#include "wc_eclipse.h"

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W	400
#define VIEW_H	400

int					gWindowW;
int					gWindowH;
struct wc_cube_t	gCube;
struct wcRectF		gRect;
struct wcEclipse	gEclipse;

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
	
	SetWcPoint(&origin, gWindowW / 2.0F, gWindowH / 2.0F, 0.0F);
	wcRectFInitilize(&gRect, &origin, gWindowW / 4.0F, gWindowH / 4.0F);

	wcEclipseInitialize(&gEclipse, 300, origin.x, origin.y,
						gWindowW / 4.0F, gWindowH / 4.0F);
}

void main_destroy_func()
{
	wcEclipseDestroy(&gEclipse);
}

void main_reshape_func(int w, int h)
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
}

void main_display_func()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableClientState(GL_VERTEX_ARRAY);

	glColor4f(1.0F, 0.0F, 0.0F, 0.0F);
	//cube_quad(&gCube, 2, 3, 7, 6);
	//wcRectFDraw(&gRect);
	wcEclipseDraw(&gEclipse);

	glutSwapBuffers();
}
