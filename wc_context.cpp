#include "wc_context.h"

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
}

// static
WcContext *WcContext::NewWcContext()
{
	return new WcContext();
}
