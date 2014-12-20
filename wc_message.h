#ifndef WC_MESSAGE_H
#define WC_MESSAGE_H

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include "wc_time.h"

struct WcMessage
{
public:
	WcMessage(int w) :
		what(w),
		arg0(0),
		arg1(0),
		data(NULL),
		time(kTimeMillisNull)
	{
	}

	WcMessage(int w, int arg0, int arg1) :
		what(w),
		arg0(arg0),
		arg1(arg1),
		data(NULL),
		time(kTimeMillisNull)
	{
	}

	WcMessage(int w, int arg0, int arg1, void *data) :
		what(w),
		arg0(arg0),
		arg1(arg1),
		data(data),
		time(kTimeMillisNull)
	{
	}

	std::string ToString() const;

	int			what;
	int			arg0;
	int			arg1;
	void		*data;
	millis_t	time;
};

#endif
