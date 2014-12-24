#ifndef WC_TIME_H
#define WC_TIME_H

#include <stdint.h>
#include <time.h>

#include <string>

typedef int64_t			millis_t;
typedef uint64_t		umillis_t;

#define WC_TIME_MILLIS_PER_SECOND	1000
#define WC_TIME_NANOS_PER_MILLIS	1000000
#define WC_TIME_NANOS_PER_SECOND	1000000000

class WcTime
{
public:
	static const millis_t kTimeMillisNull;
public:
	enum TimeValueSepc
	{
		kYear = 0,
		kMonth,
		kDay,
		kHour,
		kMinute,
		kSecond,
		kMillis,
	};

	enum Month
	{
		kJanuary = 1,
		kFebruary,
		kMarth,
		kApril,
		kMay,
		kJune,
		kJuly,
		kAugust,
		kSeptember,
		kOctober,
		kNovember,
		kDecember,
	};

	WcTime();
	WcTime(millis_t millis);

	void SetNull()
	{
		this->mMillis = -1;
	}

	bool IsNull() const {
		return mMillis == -1;
	}

	int		Get(TimeValueSepc spec) const;
	void	Set(TimeValueSepc spec, int value);

	std::string ToString() const;

	static millis_t CurrentTimeMillis();
	static bool		IsLeapYear(int year);
private:
	void UpdateFromMillis();
private:
	millis_t	mMillis;
	struct tm	mTime;
};

static inline bool TimeLess(millis_t lhs, millis_t rhs)
{
	return (umillis_t)lhs < (umillis_t)rhs;
}

static inline bool TimeGreate(millis_t lhs, millis_t rhs)
{
	return (umillis_t) rhs < (umillis_t)lhs;
}

static inline bool TimeGreateEqual(millis_t lhs, millis_t rhs)
{
	return (umillis_t) rhs <= (umillis_t) lhs;
}

static inline bool TimeLessEqual(millis_t lhs, millis_t rhs)
{
	return (umillis_t) lhs <= (umillis_t) rhs;
}

#endif
