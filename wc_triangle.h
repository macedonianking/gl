#ifndef WC_TRIANGLE_H
#define WC_TRIANGLE_H

#include "wc_point.h"

class WcTriangle
{
public:
	WcTriangle();

	WcTriangle(const wcPt3f &pt0,
			   const wcPt3f &pt1,
			   const wcPt3f &pt2);

	const GLfloat *GetGlPointer() const
	{
		return mBuffer[0].GetGlPointer();
	}

	GLfloat *GetGlPointer()
	{
		return mBuffer[0].GetGlPointer();
	}

	void SetPoints(const wcPt3f &pt0,
				   const wcPt3f &pt1,
				   const wcPt3f &pt2);

	void Draw();
private:
	wcPt3f	mBuffer[3];	
};

#endif // WC_TRIANGLE_H
