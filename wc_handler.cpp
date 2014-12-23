#include "wc_handler.h"

#include "wc_looper.h"
#include "wc_message_queue.h"

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

void WcHandler::HandleMessage(WcMessage &msg)
{
}

void WcHandler::HandleClearMessage(WcMessage &msg)
{
}
