#include "wc_context.h"

#include "wc_context9.h"
#include "wc_rect.h"

static WcContext	*gContext;

WcContext::WcContext() :
	mWindowW(500),
	mWindowH(500),
	mDrawHoriLine(true),
	mDrawVertLine(true),
	mCoordLineColor(WC_COLOR_BLUE),
	mBackgroundColor(WC_COLOR_WHITE)
{
	mHandler = new WcHandler();
	mHandler->SetTarget(this);
}

WcContext::~WcContext()
{
	delete mHandler;
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
	int zNear, zFar;

	rect.left = -mWindowW / 2;
	rect.bottom = -mWindowH / 2;
	rect.right = rect.left + mWindowW;
	rect.top = rect.bottom + mWindowH;
	zNear = rect.left;
	zFar = rect.right;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(rect.left, rect.right, rect.bottom, rect.top, zNear, zFar);

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

void WcContext::HandleMessage(WcMessage &msg)
{
}

void WcContext::HandleClearMessage(WcMessage &msg)
{
}

// static
WcContext *WcContext::GetCurrentContext()
{
	if (!gContext)
	{
		gContext = new WcContext9();
	}
	return gContext;
}

