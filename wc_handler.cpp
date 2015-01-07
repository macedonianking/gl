#include "wc_handler.h"

#include "wc_looper.h"
#include "wc_message_queue.h"

WcHandler::WcHandler() :
	WcHandler(WcLooper::MainLooper())
{
}

WcHandler::WcHandler(WcLooper *looper) :
	mQueue(looper->mQueue)
{
}

WcHandler::~WcHandler()
{
	if (mQueue != NULL) {
		mQueue->DoDeleteMessageForHandler(this);
		mQueue = NULL;
	}
}

bool WcHandler::PostMessage(int what)
{
	return PostMessage(WcMessage(what));
}

bool WcHandler::PostMessage(int what, int arg0, int arg1)
{
	return PostMessage(WcMessage(what, arg0, arg1));
}

bool WcHandler::PostMessage(int what, int arg0, int arg1, void *data)
{
	return PostMessage(WcMessage(what, arg0, arg1, data));
}

bool WcHandler::PostMessage(const WcMessage &msg)
{
	if (mQueue != NULL)
	{
		WcMessage newMsg = msg;
		newMsg.time = WcTime::kTimeMillisNull;
		newMsg.handler = this;
		mQueue->AddMessage(newMsg);
		return true;
	}
	return false;
}

bool WcHandler::PostMessageDelayed(int what, millis_t delay)
{
	return PostMessageDelayed(WcMessage(what), delay);
}

bool WcHandler::PostMessageDelayed(int what, int arg0, int arg1,
								   millis_t delay)
{
	return PostMessageDelayed(WcMessage(what, arg0, arg1), delay);
}

bool WcHandler::PostMessageDelayed(int what, int arg0, int arg1, void *data,
								   millis_t delay)
{
	return PostMessageDelayed(WcMessage(what, arg0, arg1, data), delay);
}

bool WcHandler::PostMessageDelayed(const WcMessage &msg, millis_t delay)
{
	if (mQueue != NULL)
	{
		WcMessage newMsg = msg;
		if (delay < 0)
			delay = 0;
		newMsg.time = delay + WcTime::CurrentTimeMillis();
		newMsg.handler = this;
		mQueue->AddMessage(newMsg);
		return true;
	}
	return false;
}

void WcHandler::RemoveMessage(int what)
{
	mQueue->DoDeleteMessage(this, what);
}

void WcHandler::HandleMessage(WcMessage &msg)
{
	if (mTarget != NULL)
		mTarget->HandleMessage(msg);
}

void WcHandler::HandleClearMessage(WcMessage &msg)
{
	if (mTarget != NULL)
		mTarget->HandleClearMessage(msg);
}
