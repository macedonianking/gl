#include "quad_test.h"

#include <iostream>

#include "main_application.h"
#include "base_config.h"
#include "wc_eclipse.h"
#include "wc_line.h"
#include "wc_color.h"
#include "wc_rect.h"
#include "wc_triangle.h"
#include "wc_matrix.h"
#include "wc_context.h"

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W  600
#define VIEW_H	300 

int					gWindowW;
int					gWindowH;

extern GLuint		gWindowSizeX;
extern GLuint		gWindowSizeY;

static struct WcContext *gContext = NULL;

void QuadTestInitialize()
{
	struct main_entry_t *ptr;
	if(gContext == NULL)
	{
		gContext = WcContext::NewWcContext();
	}

	ptr = &gMainEntry;
	ptr->mGLUTMode = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
	ptr->mWindowTitle = "GLUTCubeTest";
	ptr->mWindowPointX = 300;
	ptr->mWindowPointY = 300;
	ptr->mWindowSizeX = gContext->GetWindowWidth();
	ptr->mWindowSizeY = gContext->GetWindowHeight();
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
	if (gContext == NULL)
	{
		gContext = WcContext::NewWcContext();
	}
}

void main_destroy_func()
{
	if (gContext)
	{
		delete gContext;
		gContext = NULL;
	}
}

void main_reshape_func(int w, int h)
{
	if (gContext != NULL)
	{
		gContext->SetWindowSize(w, h);
	}
}

void main_display_func()
{
	if (gContext)
	{
		gContext->Draw();
	}
}

