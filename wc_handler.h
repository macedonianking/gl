#ifndef WC_HANDLER_H
#define WC_HANDLER_H

#include "wc_message.h"

class WcMessageQueue;
class WcLooper;

class WcHandlerTarget
{
public:
	WcHandlerTarget()
	{
	}

	virtual ~WcHandlerTarget()
	{
	}

	virtual void HandleMessage(WcMessage &msg)
	{
	}

	virtual void HandleClearMessage(WcMessage &msg)
	{
	}
};

class WcHandler
{
public:
	WcHandler();
	WcHandler(WcLooper *looper);

	virtual ~WcHandler();

	void SetTarget(WcHandlerTarget *target)
	{
		this->mTarget = target;
	}

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
	
	void RemoveMessage(int what);

	virtual void HandleMessage(WcMessage &msg);
	virtual void HandleClearMessage(WcMessage &msg);
private:
	WcMessageQueue		*mQueue;
	WcHandlerTarget		*mTarget;
};

#endif // WC_HANDLER_H
