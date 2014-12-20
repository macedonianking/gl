#ifndef WC_MESSAGE_QUEUE_H
#define WC_MESSAGE_QUEUE_H

#include <deque>

#include "wc_message.h"

class WcHandler;
class WcLooper;

class WcMessageQueue
{
private:
	typedef std::deque<WcMessage>			MessageQueue;
	typedef MessageQueue::iterator			iterator;
	typedef MessageQueue::const_iterator	const_iterator;

	WcLooper		*mLooper;
	WcHandler		*mHandler;

	MessageQueue	mNQueue;
	MessageQueue	mDQueue;

public:
	WcMessageQueue(WcLooper *looper, WcHandler *handler);
	virtual ~WcMessageQueue();

	void HandleMessages();
	void AddMessage(const WcMessage& msg);
	void Clear();

	friend class WcLooper;
private:
	void ResetLooper()
	{
		this->mLooper = NULL;
	}

	void HandleNMessages();
	void HandleDMessages();
	void DoClearMessageQueue(MessageQueue &queue);
	void NotifyQueueChanged();

};

#endif // WC_MESSAGE_QUEUE_H
