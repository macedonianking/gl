#ifndef WC_HANDLER_H
#define WC_HANDLER_H

#include "wc_message.h"

class WcMessageQueue;
class WcLooper;

class WcHandler
{
public:
	WcHandler();
	WcHandler(WcLooper *looper);

	virtual ~WcHandler();

	bool PostMessage(int what);
	bool PostMessage(int what, int arg0, int arg1);
	bool PostMessage(int what, int arg0, int arg1, void *data);
	bool PostMessage(const WcMessage &msg);

	bool PostMessageDelayed(int what, millis_t delay);
	bool PostMessageDelayed(int what, int arg0, int arg1, 
							millis_t delay);
	bool PostMessageDelayed(int what, int arg0, int arg1, void *data,
							millis_t delay);
	bool PostMessageDelayed(const WcMessage &msg, 
							millis_t delay);

	virtual void HandleMessage(WcMessage &msg);
	virtual void HandleClearMessage(WcMessage &msg);
private:
	WcMessageQueue		*mQueue;
};

#endif // WC_HANDLER_H
