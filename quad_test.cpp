#include "quad_test.h"

#include <iostream>

#include "main_application.h"
#include "base_config.h"
#include "wc_eclipse.h"
#include "wc_line.h"
#include "wc_color.h"
#include "wc_rect.h"

static struct main_entry_t gMainEntry;

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);
static void main_destroy_func();

#define VIEW_W  800	
#define VIEW_H  600	

int					gWindowW;
int					gWindowH;

static GLuint		gWindowSizeX;
static GLuint		gWindowSizeY;

class WcContext
{
public:
	WcContext(GLsizei w, GLsizei h)
		: mWidth(w),
		  mHeight(h),
		  mColor(WC_COLOR_RED)
	{
		SetWindowSize(w, h);
	}

	virtual ~WcContext();

	void SetWindowSize(size_t w, size_t h);

	virtual void Draw();

private:
	GLsizei			mWidth;
	GLsizei			mHeight;
	wcColor			mColor;
	wcRectF			mBound;

	WcLine			mVertLine;
	WcLine			mHoriLine;
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
	wcPt3f origin;

	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);

	if (!gContext)
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
	GLint l, t, r, b;

	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);

	gWindowSizeX = w;
	gWindowSizeY = h;
	
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	l = - (w >> 1);
	r = l + w;
	b = - (h >> 1);
	t = b + h;
	gluOrtho2D(l, r, b, t);
	if (gContext == NULL)
	{
		gContext = new WcContext(w, h);
	}
	else
	{
		gContext->SetWindowSize(w, h);
	}
}

void main_display_func()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glColor4f(1.0F, 0.0F, 0.0F, 0.0F);
	glClear(GL_COLOR_BUFFER_BIT);

	if (gContext)
	{
		gContext->Draw();
	}

	glutSwapBuffers();
}

WcContext::~WcContext()
{
}

void WcContext::SetWindowSize(size_t w, size_t h)
{
	GLsizei x, y;

	this->mWidth = w;
	this->mHeight = h;

	x = w >> 1;
	y = h >> 1;
	mHoriLine.SetFmPoint(wcPt3f(-x, 0.0F));
	mHoriLine.SetToPoint(wcPt3f(x, 0.0F));
	mVertLine.SetFmPoint(wcPt3f(0.0F, -y));
	mVertLine.SetToPoint(wcPt3f(0.0F, y));

	mBound.SetXYWH(100.0F, 100.0F, 100.0F, 100.0F);
}

void WcContext::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glColor3fv(reinterpret_cast<GLfloat*>(&mColor));	
	glBegin(GL_POINTS);
		glVertex3f(0.0F, 0.0F, 0.0F);
	glEnd();

	mVertLine.Draw();
	mHoriLine.Draw();
	
	glPushMatrix();
	glTranslatef(-mBound.GetCenterX(), -mBound.GetCenterY(), 0.0F);
	glRotatef(45.0F, 0.0F, 0.0F, 1.0F);
	glTranslatef(mBound.GetCenterX(), mBound.GetCenterY(), 0.0F);
	mBound.Draw(GL_POLYGON);
	glPopMatrix();
}
