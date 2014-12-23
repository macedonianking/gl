#include "wc_time.h"

#include <time.h>
#include <sys/time.h>

#include <sstream>

#define WC_TIME_START_YEAR

extern const millis_t kTimeMillisNull = -1;

WcTime::WcTime()
	: mMillis(WcTime::CurrentTimeMillis())
{
}

WcTime::WcTime(millis_t millis)
	: mMillis(millis)
{
}

void WcTime::UpdateFromMillis()
{
	time_t second;

	second = static_cast<time_t>(mMillis / WC_TIME_MILLIS_PER_SECOND);
	localtime_r(&second, &mTime);
}

int WcTime::Get(WcTime::TimeValueSepc spec) const
{
	switch(spec)
	{
		case kYear:
			return mTime.tm_year;
		case kMonth:
			return mTime.tm_mon;
		case kDay:
			return mTime.tm_mday;
		case kHour:
			return mTime.tm_hour;
		case kMinute:
			return mTime.tm_min;
		case kSecond:
			return mTime.tm_sec;
		case kMillis:
			return mMillis % (millis_t) WC_TIME_MILLIS_PER_SECOND;
	}
	return 0;
}

void WcTime::Set(WcTime::TimeValueSepc spec, int value)
{
}

std::string WcTime::ToString() const
{
	char buffer[1024];
	
	strftime(buffer, 1024, "%c", &mTime);
	return std::string(buffer);
}

bool WcTime::IsLeapYear(int year)
{
	return ((year%4) == 0 && (year%100) != 0) || (year % 100) == 0;
}

millis_t WcTime::CurrentTimeMillis()
{
	struct timespec value;
	millis_t millis;

	clock_gettime(CLOCK_MONOTONIC, &value);
	millis = static_cast<millis_t>(value.tv_sec);
	millis += static_cast<millis_t>(value.tv_nsec / WC_TIME_NANOS_PER_MILLIS);
	return millis;
}
