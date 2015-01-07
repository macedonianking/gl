#ifndef WC_CONTEXT_H
#define WC_CONTEXT_H

#include "base_config.h"
#include "wc_color.h"
#include "wc_line.h"
#include "wc_handler.h"

#define CONTEXT_FPS_DEFAULT	60

#define TIMER_ID_UI		1000

#include <vector>

class WcAnimator;

class WcContext : public WcHandlerTarget
{
public:
	WcContext();
	virtual ~WcContext();

	void SetFPS(int fps);

	void Invalidate();
	void InvalidateFPS();

	virtual int GetWindowWidth()
	{
		return mWindowW;
	}

	virtual int GetWindowHeight()
	{
		return mWindowH;
	}

	virtual void SetWindowSize(GLsizei w, GLsizei h);
	virtual void OnSetProjectionMatrix();

	virtual void Draw();
	virtual bool OnUpdate();
	virtual void OnDraw();

	// WcHandlerTarget methods
	virtual void HandleMessage(WcMessage &msg) override;
	virtual void HandleClearMessage(WcMessage &msg) override;

	static WcContext *GetCurrentContext();

	void 	AddAnimator(WcAnimator *animator);
	void 	DelAnimator(WcAnimator *animator);
private:
	bool UpdateAnimators();

protected:
	int 		mPrivateFlags;
	GLsizei		mWindowW;
	GLsizei		mWindowH;
	int			mFPS;
	millis_t	mFPSPeriod;
	millis_t  	mLastUpdateMillis;

	bool		mTimerRunning;
	bool		mDrawHoriLine;
	bool		mDrawVertLine;

	WcColorF	mCoordLineColor;
	WcLineI		mHoriLine;
	WcLineI		mVertLine;

	WcColorF	mBackgroundColor;
	WcHandler	*mHandler;

	std::vector<WcAnimator*> mAnimatorList;
};

#endif // WC_CONTEXT_H
