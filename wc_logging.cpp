#include "wc_logging.h"

#include "wc_time.h"

LogMessage::LogMessage(LogLevel level, const char *file, int line) :
	mShouldPrintMessage(true),
	mLevel(level), 
	mFile(file),
	mLine(line)
{
}

LogMessage::~LogMessage()
{
	if (mShouldPrintMessage)
		PrintMessage();
}

void LogMessage::PrintMessage()
{
	if (!this->IsMessageEmpty())
	{
		this->PrintMessageHeader(std::cout);
		this->PrintMessageContent(std::cout);
		std::cout << std::endl;
	}
}

bool LogMessage::IsMessageEmpty()
{
	bool empty;

	streampos pos = tellp();
	seekp(0, std::ios::end);
	empty = tellp() == 0;
	seekp(pos);

	return empty;
}

void LogMessage::PrintMessageHeader(std::ostream &out)
{
	char buffer[1024];
	time_t timeSeconds;
	struct tm tmCalendar;

	timeSeconds = time(NULL);
	localtime_r(&timeSeconds, &tmCalendar);
	strftime(buffer, 1024, "%F %T", &tmCalendar);	
	out << buffer << " [" << mFile << ":" << mLine << "]";
}

void LogMessage::PrintMessageContent(std::ostream &out)
{
	out << str();
}
