#ifndef WC_LINE_H
#define WC_LINE_H

#include "wc_point.h"

void wcDrawLine();

class WcLine
{
public:
	WcLine()
	{
	}

	WcLine(const wcPt3f &fm, const wcPt3f &to)
		: mPointFm(fm),
		  mPointTo(to)
	{
	}

	void Draw();

	void SetFmPoint(const wcPt3f& pt)
	{
		this->mPointFm = pt;
	}

	void SetToPoint(const wcPt3f& pt)
	{
		this->mPointTo = pt;
	}

	const wcPt3f& GetFmPoint() const
	{
		return this->mPointFm;
	}

	const wcPt3f& GetToPoint() const
	{
		return this->mPointTo;
	}

private:
	wcPt3f	mPointFm;
	wcPt3f	mPointTo;
};

#endif 
