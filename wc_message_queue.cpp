#include "wc_message_queue.h"

#include "wc_looper.h"
#include "wc_time.h"
#include "wc_handler.h"
#include "wc_looper.h"

WcMessageQueue::WcMessageQueue(WcLooper *looper) :
	mLooper(looper)
{
}

WcMessageQueue::~WcMessageQueue()
{
	this->Clear();
}

void WcMessageQueue::AddMessage(const WcMessage &msg)
{
	MessageQueue *ptr = &this->mNQueue;

	if (msg.time == WcTime::kTimeMillisNull)
	{
		ptr->push_back(msg);
		NotifyQueueChanged();
		return;
	}

	ptr = &this->mDQueue;
	iterator iter = ptr->begin();
	while (iter != ptr->end() && TimeLess(iter->time, msg.time))
	{
		++iter;
	}
	ptr->insert(iter, msg);	
	NotifyQueueChanged();
}

void WcMessageQueue::DelMessage(int what)
{
	bool changed = false;

	if (DoDeleteMessage(mNQueue, what))
	{
		changed = true;
	}

	if (DoDeleteMessage(mDQueue, what))
	{
		changed = true;
	}

	if (changed)
	{
		NotifyQueueChanged();		
	}
}

void WcMessageQueue::DoDeleteMessageForHandler(WcHandler *handler)
{
	bool r = false;

	r |= DoDeleteMessageForHandler(mNQueue, handler);
	r |= DoDeleteMessageForHandler(mDQueue, handler);

	if (r)
	{
		NotifyQueueChanged();
	}
}

bool WcMessageQueue::DoDeleteMessage(MessageQueue &queue, int what)
{
	bool r = false;

	iterator iter = queue.begin();
	while (iter != queue.end())	
	{
		if (iter->what == what)
		{
			iter = queue.erase(iter);
			r = true;
		}
		else
		{
			++iter;
		}
	}

	return r;
}

bool WcMessageQueue::DoDeleteMessageForHandler(MessageQueue &queue, 
											   WcHandler *handler)
{
	bool r = false;

	iterator iter = queue.begin();
	while (iter != queue.end())
	{
		if (iter->handler == handler)
		{
			iter = queue.erase(iter);
			r = true;
		}
		else
		{
			++iter;
		}
	}

	return r;
}

void WcMessageQueue::Clear()
{
	DoClearMessageQueue(mNQueue);
	DoClearMessageQueue(mDQueue);
	NotifyQueueChanged();
}

bool WcMessageQueue::Next(WcMessage *msg)
{
	if (!mNQueue.empty())
	{
		*msg = mNQueue.front();
		mNQueue.pop_front();
		return true;
	}

	if (!mDQueue.empty())
	{
		WcMessage& ref = mDQueue.front();
		if (TimeLessEqual(ref.time, WcTime::CurrentTimeMillis()))
		{
			*msg = ref;
			mDQueue.pop_front();
			return true;
		}
	}

	return false;
}

void WcMessageQueue::DoClearMessageQueue(
								WcMessageQueue::MessageQueue &queue)
{
	while (!queue.empty())
	{
		WcMessage &msg = queue.front();
		msg.handler->HandleClearMessage(msg);
		queue.pop_front();
	}
}

void WcMessageQueue::NotifyQueueChanged()
{
	if (mLooper != NULL)
	{
		mLooper->Update();
	}
}

bool WcMessageQueue::NextTime(millis_t *dstMillis) const
{
	millis_t now;

	now = WcTime::CurrentTimeMillis();
	if (!mNQueue.empty())
	{
		if (dstMillis != NULL) 
			*dstMillis = now;
		return true;
	}

	if (!mDQueue.empty())
	{
		if (TimeLessEqual(now, mDQueue.front().time))
		{
			if (dstMillis != NULL) 
				*dstMillis = mDQueue.front().time;
		}
		else
		{
			if (dstMillis != NULL)
				*dstMillis = now;
		}
		return true;
	}

	return false;
}
