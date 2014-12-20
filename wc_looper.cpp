#include "wc_looper.h"

#include "wc_message_queue.h"

#include <algorithm>

WcLooper::WcLooper()
{
}

WcLooper::~WcLooper()
{
}

WcMessageQueue *WcLooper::CreateMessageQueue(WcHandler *handler)
{
	WcMessageQueue *queue;

	queue = new WcMessageQueue(this, handler);
	this->mQueue.push_back(queue);
	return queue;
}

void WcLooper::RemoveMessageQueue(WcMessageQueue *queue)
{
	iterator iter = std::find(mQueue.begin(), mQueue.end(), queue);
	if (iter != mQueue.end())
	{
		mQueue.erase(iter);	
	}
}
