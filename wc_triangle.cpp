#include "wc_triangle.h"

template<>
void WcTriangleT<GLfloat>::Draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i != 3; ++i)
	{
		glVertex4fv(mBuffer[i].GetGlPointer());
	}
	glEnd();
}

template<>
void WcTriangleT<GLdouble>::Draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i != 3; ++i)
	{
		glVertex4dv(mBuffer[i].GetGlPointer());
	}
	glEnd();
}
