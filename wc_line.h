#ifndef WC_LINE_IMPL_H
#define WC_LINE_IMPL_H

#include "wc_point.h"

template<typename Tp>
class WcLineT
{
public:
	typedef WcPoint4T<Tp> Point;

	WcLineT()
	{
	}

	WcLineT(const Point &fm, const Point &to) : 
		mFmPoint(fm),
		mToPoint(to)
	{
	}

	void Draw();

	void SetFmPoint(const Point& pt)
	{
		this->mFmPoint = pt;
	}

	void SetToPoint(const Point& pt)
	{
		this->mToPoint = pt;
	}

	const Point& GetFmPoint() const
	{
		return this->mFmPoint;
	}

	const Point& GetToPoint() const
	{
		return this->mToPoint;
	}

public:
	Point	mFmPoint;
	Point	mToPoint;
};

template<typename Tp>
void WcLineT<Tp>::Draw()
{
}

typedef WcLineT<GLfloat>	WcLineF;
typedef WcLineT<GLdouble>	WcLineD;
typedef	WcLineT<GLint>		WcLineI;

#endif // WC_LINE_IMPL_H
