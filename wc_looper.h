#ifndef WC_MESSAGE_LOOP_H
#define WC_MESSAGE_LOOP_H

#include "base_config.h"

#include <stdint.h>

#include <deque>

class WcMessageQueue;
class WcHandler;

extern void WcLooperTimerFunc(int id);

class WcLooper
{
public:
	static void		InitMainLooper();
	static void		DeleteMainLooper(); 
	static WcLooper *MainLooper();
private:
	static WcLooper *sMainLooper;
public:
	WcLooper();
	~WcLooper();

	friend class WcMessageQueue;
	friend class WcHandler;
	friend void WcLooperTimerFunc(int id);
private:
	void		Update();
	void		OnTimerUpdate();

private:
	int				mId;	
	WcMessageQueue	*mQueue;
};

#endif
