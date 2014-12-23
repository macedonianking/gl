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

	MessageQueue	mNQueue;
	MessageQueue	mDQueue;

public:
	WcMessageQueue(WcLooper *looper);
	virtual ~WcMessageQueue();

	void		AddMessage(const WcMessage& msg);
	void		DelMessage(int what);
	void		Clear();
	bool		Next(WcMessage *msg);
	bool		NextTime(millis_t *dstMillis) const;

	friend class WcLooper;
	friend class WcHandler;
private:
	bool DoDeleteMessage(MessageQueue &queue, int what);
	void DoDeleteMessageForHandler(WcHandler *handler);
	bool DoDeleteMessageForHandler(MessageQueue &queue, WcHandler *handler);
	void DoClearMessageQueue(MessageQueue &queue);
	void NotifyQueueChanged();
};

#endif // WC_MESSAGE_QUEUE_H
