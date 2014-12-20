#include "wc_message.h"

#include <sstream>

std::string WcMessage::ToString() const
{
	std::stringstream out;

	out << "WcMessage:" << std::showbase << std::nouppercase << std::hex
		<< this << " ["
		<< std::noshowbase << std::dec
		<< "what=" << what << ","
		<< "arg0=" << arg0 << ","
		<< "arg1=" << arg1 << ","
		<< std::showbase << std::nouppercase << std::hex
		<< "data=" << data << ","
		<< std::noshowbase << std::dec
		<< "time=" << time << "]";
	return out.str();
}
