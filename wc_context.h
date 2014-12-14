#ifndef WC_CONTEXT_H
#define WC_CONTEXT_H

#include "base_config.h"
#include "wc_color.h"

class WcContext
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
	virtual void Draw();
	virtual void OnDraw();

	static WcContext *NewWcContext();
protected:
	GLsizei		mWindowW;
	GLsizei		mWindowH;

	wcColor		mBackgroundColor;
};

#endif // WC_CONTEXT_H
