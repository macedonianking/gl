#ifndef WC_TIME_H
#define WC_TIME_H

#include <stdint.h>

typedef int64_t			millis_t;
typedef uint64_t		umillis_t;

static const millis_t kTimeMillisNull	= -1;

class WcTime
{
public:
	WcTime();
	WcTime(millis_t millis);

	void SetNull()
	{
		this->mMillis = -1;
	}

	bool IsNull() const {
		return mMillis == -1;
	}

	static millis_t CurrentTimeMillis();
private:
	millis_t mMillis;
};

static inline bool  TimeBefore(millis_t lhs, millis_t rhs)
{
	return (umillis_t)lhs < (umillis_t)rhs;
}

static inline bool  TimeAfter(millis_t lhs, millis_t rhs)
{
	return (umillis_t) rhs < (umillis_t)lhs;
}

static inline bool  TimeNotBefore(millis_t lhs, millis_t rhs)
{
	return (umillis_t) rhs <= (umillis_t) lhs;
}

static inline bool  TimeNotAfter(millis_t lhs, millis_t rhs)
{
	return (umillis_t) lhs <= (umillis_t) rhs;
}

#endif
