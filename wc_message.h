#ifndef WC_MESSAGE_H
#define WC_MESSAGE_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "wc_time.h"

class WcHandler;

struct WcMessage
{
public:
	WcMessage()
		: WcMessage(0)
	{
	}

	WcMessage(int w) :
		WcMessage(w, 0, 0)	
	{
	}

	WcMessage(int w, int arg0, int arg1) :
		WcMessage(w, arg0, arg1, NULL)	
	{
	}

	WcMessage(int w, int arg0, int arg1, void *data) :
		what(w),
		arg0(arg0),
		arg1(arg1),
		data(data),
		time(kTimeMillisNull),
		handler(NULL)
	{
	}

	std::string ToString() const;

	int			what;
	int			arg0;
	int			arg1;
	void		*data;
	millis_t	time;
	WcHandler	*handler;
};

#endif
