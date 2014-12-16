#include "wc_context.h"

#include "wc_context9.h"
#include "wc_rect.h"

WcContext::WcContext() :
	mWindowW(500),
	mWindowH(500),
	mDrawHoriLine(true),
	mDrawVertLine(true),
	mCoordLineColor(WC_COLOR_BLUE),
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
	glViewport(0, 0, w, h);
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

	mHoriLine.SetFmPoint(make_point(rect.left, rect.GetCenterY()));
	mHoriLine.SetToPoint(make_point(rect.right, rect.GetCenterY()));
	mVertLine.SetFmPoint(make_point(rect.GetCenterX(), rect.bottom));
	mVertLine.SetToPoint(make_point(rect.GetCenterX(), rect.top));
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

	if (mDrawHoriLine || mDrawVertLine) {
		glColor4fv(mCoordLineColor.GetGlPointer());

		if (mDrawHoriLine) {
			mHoriLine.Draw();
		}

		if (mDrawVertLine) {
			mVertLine.Draw();
		}
	}
}

// static
WcContext *WcContext::NewWcContext()
{
	return new WcContext9();
}
