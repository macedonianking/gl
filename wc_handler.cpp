#include "wc_handler.h"

#include "wc_looper.h"
#include "wc_message_queue.h"

WcHandler::WcHandler(WcLooper *looper)
{
}

WcHandler::~WcHandler()
{
	if (mQueue != NULL)
	{
		delete mQueue;
		mQueue = NULL;
	}
}

void WcHandler::HandleMessage(WcMessage &msg)
{
}

void WcHandler::HandleClearMessage(WcMessage &msg)
{
}
