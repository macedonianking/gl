#ifndef WC_MESSAGE_LOOP_H
#define WC_MESSAGE_LOOP_H

#include <deque>

class WcMessageQueue;
class WcHandler;

class WcLooper
{
public:
	WcLooper();
	~WcLooper();

	WcMessageQueue *CreateMessageQueue(WcHandler *handler);

	friend class WcMessageQueue;
private:
	void RemoveMessageQueue(WcMessageQueue *queue);

private:
	typedef std::deque<WcMessageQueue*> QueueList;	
	typedef QueueList::iterator			iterator;
	typedef QueueList::const_iterator	const_iterator;

	QueueList		mQueue;
};

#endif
