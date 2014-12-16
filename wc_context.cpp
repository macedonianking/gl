#include "wc_context.h"

#include "wc_context9.h"
#include "wc_rect_impl.h"

WcContext::WcContext() :
	mWindowW(500),
	mWindowH(500),
	mBackgroundColor(WC_COLOR_WHITE)
{
}

WcContext::~WcContext()
{
}

void WcContext::SetWindowSize(GLsizei w, GLsizei h)
{
	this->mWindowW = w;
	this->mWindowH = h;
	glViewport(0, w, 0, h);
	OnSetProjectionMatrix();
}

void WcContext::OnSetProjectionMatrix()
{
	WcRectT<int> rect;

	rect.left = -mWindowW / 2;
	rect.bottom = -mWindowH / 2;
	rect.right = rect.left + mWindowW;
	rect.top = rect.bottom + mWindowH;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(rect.left, rect.right, rect.bottom, rect.top);
}

void WcContext::Draw()
{
	glClearColor(mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b,mBackgroundColor.a);
	glClearDepth(0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	OnDraw();

	glutSwapBuffers();
}

void WcContext::OnDraw()
{	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// static
WcContext *WcContext::NewWcContext()
{
	return new WcContext9();
}
