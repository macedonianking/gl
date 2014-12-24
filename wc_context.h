#ifndef WC_CONTEXT_H
#define WC_CONTEXT_H

#include "base_config.h"
#include "wc_color.h"
#include "wc_line.h"
#include "wc_handler.h"

#define CONTEXT_FPS_DEFAULT	60

#define TIMER_ID_UI		1000

class WcContext : public WcHandlerTarget
{
public:
	WcContext();
	virtual ~WcContext();

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
	virtual void OnDraw();

	// WcHandlerTarget methods
	virtual void HandleMessage(WcMessage &msg) override;
	virtual void HandleClearMessage(WcMessage &msg) override;

	static WcContext *GetCurrentContext();

protected:
	GLsizei		mWindowW;
	GLsizei		mWindowH;
	int			mFPS;

	bool		mTimerRunning;
	bool		mDrawHoriLine;
	bool		mDrawVertLine;

	WcColorF	mCoordLineColor;
	WcLineI		mHoriLine;
	WcLineI		mVertLine;

	WcColorF	mBackgroundColor;
	WcHandler	*mHandler;
};

#endif // WC_CONTEXT_H
