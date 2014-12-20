#ifndef WC_HANDLER_H
#define WC_HANDLER_H

#include "wc_message.h"

class WcMessageQueue;
class WcLooper;

class WcHandler
{
public:
	WcHandler(WcLooper *looper);

	virtual ~WcHandler();

	bool PostMessage(const WcMessage &msg);
	bool PostMessageDelayed(const WcMessage );

	void AssertPostMessage(const WcMessage &msg);
	void AssertPostMessageDealyed(const WcMessage &msg, int64_t delay);

	virtual void HandleMessage(WcMessage &msg);
	virtual void HandleClearMessage(WcMessage &msg);
private:
	WcMessageQueue		*mQueue;
};

#endif // WC_HANDLER_H
