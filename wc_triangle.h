#ifndef WC_TRIANGLE_H
#define WC_TRIANGLE_H

#include "wc_point.h"

template<typename Tp>
class WcTriangleT
{
public:
	typedef	WcPoint4T<Tp>	Point;

	WcTriangleT();
	WcTriangleT(const Point &pt0,
			    const Point &pt1,
			    const Point &pt2);

	const Tp *GetGlPointer() const
	{
		return mBuffer[0].GetGlPointer();
	}

	Tp *GetGlPointer()
	{
		return mBuffer[0].GetGlPointer();
	}

	void SetPoints(const Point &pt0,
				   const Point &pt1,
				   const Point &pt2);

	void Draw();
private:
	Point	mBuffer[3];	
};

template<typename Tp>
WcTriangleT<Tp>::WcTriangleT()
{
}

template<typename Tp>
WcTriangleT<Tp>::WcTriangleT(const Point &pt0, 
							 const Point &pt1,
							 const Point &pt2)
{
	this->mBuffer[0] = pt0;
	this->mBuffer[1] = pt1;
	this->mBuffer[2] = pt2;
}

template<typename Tp>
void WcTriangleT<Tp>::SetPoints(const Point &pt0, 
								const Point &pt1,
								const Point &pt2)
{
	this->mBuffer[0] = pt0;
	this->mBuffer[1] = pt1;
	this->mBuffer[2] = pt2;
}

template<typename Tp>
void WcTriangleT<Tp>::Draw()
{
}

typedef WcTriangleT<GLfloat>	WcTriangleF;
typedef WcTriangleT<GLdouble>	WcTriangleD;

#endif // WC_TRIANGLE_H
