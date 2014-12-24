#ifndef WC_CONTEXT9_H
#define WC_CONTEXT9_H

#include "wc_context.h"
#include "wc_triangle.h"
#include "wc_handler.h"

class WcContext9 : public WcContext
{
public:
	WcContext9();
	virtual ~WcContext9();

	virtual void SetWindowSize(int w, int h) override;
	virtual void OnDraw() override;

	virtual void HandleMessage(WcMessage &msg) override;
	virtual void HandleClearMessage(WcMessage &msg) override;
private:
	WcTriangleF		mTriangle;
};

#endif // WC_CONTEXT9_H
