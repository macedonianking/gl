#include "wc_looper.h"


#include <algorithm>
#include <vector>

#include "wc_message.h"
#include "wc_message_queue.h"
#include "wc_handler.h"

static int kWcLooperIdGenerator = 1000;
static std::vector<WcLooper*>	gLooperVector;		

WcLooper::WcLooper() :
	mId(kWcLooperIdGenerator++),
	mQueue(new WcMessageQueue(this))
{
	gLooperVector.push_back(this);
}

WcLooper::~WcLooper()
{
	delete mQueue;
	
	std::vector<WcLooper*>::iterator iter = std::find(gLooperVector.begin(),
			gLooperVector.end(), this);
	if (iter != gLooperVector.end())
	{
		gLooperVector.erase(iter);
	}
}

void WcLooper::Update()
{
	if (mQueue == NULL)
	{
		return;
	}

	millis_t dstMillis;
	if (!mQueue->NextTime(&dstMillis))
	{
		return;
	}

	dstMillis -= WcTime::CurrentTimeMillis();
	if (dstMillis < 0) 
		dstMillis = 0;

	glutTimerFunc((unsigned int)dstMillis, WcLooperTimerFunc, mId);
}

void WcLooper::OnTimerUpdate() 
{
	if (mQueue == NULL)
	{
		return;
	}

	WcMessage msg;
	for (;;)
	{
		if (!mQueue->Next(&msg))
		{
			break;
		}	

		msg.handler->HandleMessage(msg);
	}

	this->Update();
}

void WcLooperTimerFunc(int id)
{
	std::vector<WcLooper*>::iterator iter;

	for (iter = gLooperVector.begin(); iter != gLooperVector.end();
		 ++iter)
	{
		if ((*iter)->mId == id)
		{
			break;
		}
	}

	if (iter != gLooperVector.end())
	{
		(*iter)->OnTimerUpdate();
	}
}

void WcLooper::InitMainLooper()
{
	sMainLooper = new WcLooper();
}

void WcLooper::DeleteMainLooper()
{
	delete sMainLooper;
	sMainLooper = NULL;
}

WcLooper *WcLooper::MainLooper()
{
	return sMainLooper;
}

WcLooper *WcLooper::sMainLooper = NULL;
