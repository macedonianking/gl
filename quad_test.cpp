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

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W  600
#define VIEW_H	300 

int					gWindowW;
int					gWindowH;

static GLuint		gWindowSizeX;
static GLuint		gWindowSizeY;

class WcContext
{
public:
	WcContext(GLsizei w, GLsizei h)
		: mWindowW(w),
		  mWindowH(h)
	{
		SetWindowSize(w, h);
		mTriangle.SetPoints(wcPt3f(-50.0F, -25.0F),
							wcPt3f(50.0F, -25.0F),
							wcPt3f(0.0F, 25.0F));
	}

	~WcContext();

	void SetWindowSize(size_t w, size_t h);
	void Draw();
private:
	void DrawTriangle(GLint x, GLint y, GLint w, GLint h,
					  const wcColor &color, GLfloat zAngle);

	GLsizei		mWindowW;
	GLsizei		mWindowH;
	WcTriangle	mTriangle;
};

static struct WcContext *gContext = NULL;

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
	if (gContext == NULL)
	{
		gContext = new WcContext(VIEW_W, VIEW_H);
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

WcContext::~WcContext()
{
}

void WcContext::SetWindowSize(size_t w, size_t h)
{
	this->mWindowW = w;
	this->mWindowH = h;
}

void WcContext::Draw()
{
	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
	glClearDepth(0.0F);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	this->DrawTriangle(0, 0, 300, 300, WC_COLOR_RED, 0.0F);
	this->DrawTriangle(300, 0, 300, 300, WC_COLOR_BLUE, 90.0F);

	glutSwapBuffers();
}

void WcContext::DrawTriangle(GLint x, GLint y, GLint w, GLint h,
							const wcColor &color, GLfloat zAngle)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);

	glColor4fv(color.GetGlPointer());
	glViewport(x, y, w, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glRotatef(zAngle, 0.0F, 0.0F, 1.0F);
	mTriangle.Draw();
	glPopMatrix();
}
