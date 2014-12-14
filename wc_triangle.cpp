#include "wc_triangle.h"

WcTriangle::WcTriangle()
{
}

WcTriangle::WcTriangle(const wcPt3f &pt0, 
					   const wcPt3f &pt1,
					   const wcPt3f &pt2)
{
	this->mBuffer[0] = pt0;
	this->mBuffer[1] = pt1;
	this->mBuffer[2] = pt2;
}

void WcTriangle::SetPoints(const wcPt3f &pt0, 
			   const wcPt3f &pt1,
			   const wcPt3f &pt2)
{
	this->mBuffer[0] = pt0;
	this->mBuffer[1] = pt1;
	this->mBuffer[2] = pt2;
}

void WcTriangle::Draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i != 3; ++i)
	{
		glVertex3fv(mBuffer[i].GetGlPointer());
	}
	glEnd();
}
