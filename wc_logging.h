#ifndef GL_LOGGING_H
#define GL_LOGGING_H

#include <assert.h>
#include <iostream>
#include <sstream>

#ifndef ASSERT_FAILURE
#define ASSERT_FAILURE()	asset(false)
#endif

#ifndef NDEBUG
#define	DASSERT(cond)
#else
#define DASSERT(cond)	assert(cond)
#endif

#define LOG(level)	LogMessage(level, __FILE__, __LINE__)
#define DCHECK(cond) LogDCheck(cond, ERROR, __FILE__, __LINE__)

enum LogLevel
{
	VERBOSE = 0,
	INFO,
	DEBUG,
	WARNING,
	ERROR,
};

class LogMessage : public std::stringstream
{
private:
	bool				mShouldPrintMessage;
	int					mLevel;
	const char			*mFile;
	int					mLine;

public:
	LogMessage(LogLevel level, const char *file, int line);
	virtual ~LogMessage();

	void SetShouldPrintMessage(bool shouldPrintMessage)
	{
		this->mShouldPrintMessage = shouldPrintMessage;
	}

protected:
	void		 PrintMessage();
	virtual	bool IsMessageEmpty();
	virtual void PrintMessageHeader(std::ostream &out);
	virtual void PrintMessageContent(std::ostream &out);
};

class LogDCheck : public LogMessage
{
public:
	LogDCheck(bool result, LogLevel level, const char *file, int line)
		: LogMessage(level, file, line),
		  mResult(result)
	{
		SetShouldPrintMessage(!result);
	}

	~LogDCheck()
	{
		DASSERT(result);
	}

private:
	bool		mResult;
};

#endif 
