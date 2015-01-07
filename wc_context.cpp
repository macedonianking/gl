#include "wc_context.h"

#include <algorithm>

#include "wc_context9.h"
#include "wc_rect.h"
#include "wc_animator.h"
#include "wc_logging.h"

static WcContext	*gContext;

#define PFLAG_WC_CONTEXT_INVALIDATE	0x0001

WcContext::WcContext() :
	mPrivateFlags(0),
	mWindowW(500),
	mWindowH(500),
	mDrawHoriLine(true),
	mDrawVertLine(true),
	mCoordLineColor(WC_COLOR_BLUE),
	mBackgroundColor(WC_COLOR_WHITE)
{
	mHandler = new WcHandler();
	mHandler->SetTarget(this);
	mLastUpdateMillis = WcTime::CurrentTimeMillis();
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

void WcContext::Invalidate()
{
	if (!(mPrivateFlags & PFLAG_WC_CONTEXT_INVALIDATE)) {
		mPrivateFlags |= PFLAG_WC_CONTEXT_INVALIDATE;
		glutPostRedisplay();
	}
}

void WcContext::InvalidateFPS() {
	millis_t delta = WcTime::CurrentTimeMillis() - mLastUpdateMillis;
	if (delta < 0) {
		Invalidate();
	}
	else if (delta < mFPSPeriod) {
		// should post message.
	}
	else 
	{
		Invalidate();
	}
}

void WcContext::Draw()
{
	bool scheduleInvalidate;

	scheduleInvalidate = false;
	mPrivateFlags &= ~(PFLAG_WC_CONTEXT_INVALIDATE);
	mLastUpdateMillis = WcTime::CurrentTimeMillis();

	OnUpdate();
	glClearColor(mBackgroundColor.r, mBackgroundColor.g, mBackgroundColor.b,mBackgroundColor.a);
	glClearDepth(0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	OnDraw();

	glutSwapBuffers();
	if (scheduleInvalidate) {
		InvalidateFPS();
	}
}

bool WcContext::OnUpdate()
{
	return UpdateAnimators();
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

void WcContext::SetFPS(int fps)
{
	if (fps < 0)
	{
		fps = 1;
	} else if (fps > 100)
	{
		fps = 100;
	}

	if (this->mFPS == fps)
	{
		return;
	}
	this->mFPSPeriod = 1000000 / this->mFPS;
}

void WcContext::AddAnimator(WcAnimator *animator)
{
	DCHECK(animator);	
	if (std::find(mAnimatorList.begin(), mAnimatorList.end(), animator) 
		== mAnimatorList.end()) {
		mAnimatorList.push_back(animator);
	}
}

void WcContext::DelAnimator(WcAnimator *animator) {
	DCHECK(animator);
	std::vector<WcAnimator*>::iterator iter;
	for (iter = mAnimatorList.begin(); iter != mAnimatorList.end();
		 ++iter)
	{
		if (*iter == animator) {
			mAnimatorList.erase(iter);
		}
	}
}

bool WcContext::UpdateAnimators()
{
	if (mAnimatorList.empty()) {
		return false;
	}

	bool r = false;
	std::vector<WcAnimator*> animators(mAnimatorList);
	std::vector<WcAnimator*>::iterator iter;
	for (iter = animators.begin(); iter != animators.end();
		 ++iter)
	{
		(*iter)->Update();
		r |= (*iter)->IsRunning();
	}

	return r;
}