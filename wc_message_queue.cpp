#include "wc_message_queue.h"

#include "wc_time.h"
#include "wc_handler.h"
#include "wc_looper.h"

WcMessageQueue::WcMessageQueue(WcLooper *looper, WcHandler *handler) :
	mLooper(looper),
	mHandler(handler)
{
}

WcMessageQueue::~WcMessageQueue()
{
	this->Clear();
	if (mLooper != NULL)
	{
		mLooper->RemoveMessageQueue(this);
		ResetLooper();
	}
	mHandler = NULL;
}

void WcMessageQueue::HandleNMessages()
{
	MessageQueue *ptr;
	   
	ptr	= &mNQueue;
	while (!ptr->empty())
	{
		mHandler->HandleMessage(ptr->front());
		ptr->pop_front();
	}
}

void WcMessageQueue::HandleDMessages()
{
	MessageQueue *ptr;

	ptr = &mDQueue;
	while (true)
	{
		if (ptr->empty())
		{
			break;
		}

		if (TimeBefore(WcTime::CurrentTimeMillis(), ptr->front().time))
		{
			break;
		}

		mHandler->HandleMessage(ptr->front());
		ptr->pop_front();
	}	
}

void WcMessageQueue::AddMessage(const WcMessage &msg)
{
	MessageQueue *ptr = &this->mDQueue;

	if (msg.time == kTimeMillisNull)
	{
		ptr->push_back(msg);
		return;
	}

	iterator iter = ptr->begin();
	while (iter != ptr->end() && TimeBefore(iter->time, msg.time))
	{
		++iter;
	}

	ptr->insert(iter, msg);	
}

void WcMessageQueue::Clear()
{
	DoClearMessageQueue(mNQueue);
	DoClearMessageQueue(mDQueue);
	NotifyQueueChanged();
}

void WcMessageQueue::DoClearMessageQueue(
								WcMessageQueue::MessageQueue &queue)
{
	while (!queue.empty())
	{
		if (mHandler != NULL)
		{
			mHandler->HandleClearMessage(queue.front());
		}
		queue.pop_front();
	}
}

void WcMessageQueue::NotifyQueueChanged()
{
}

