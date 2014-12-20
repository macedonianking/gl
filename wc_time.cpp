#include "wc_time.h"

WcTime::WcTime()
	: mMillis(WcTime::CurrentTimeMillis())
{
}

WcTime::WcTime(int64_t millis)
	: mMillis(millis)
{
}

int64_t WcTime::CurrentTimeMillis()
{
	return 0;
}
