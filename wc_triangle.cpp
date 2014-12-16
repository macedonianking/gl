#include "wc_triangle.h"

template<>
void WcTriangleT<GLfloat>::Draw()
{
	std::cout << "WcTriangleT::GLfloat" << std::endl;

	glBegin(GL_TRIANGLES);
	for (int i = 0; i != 0; ++i)
	{
		glVertex4fv(mBuffer[i].GetGlPointer());
	}
	glEnd();
}

template<>
void WcTriangleT<GLdouble>::Draw()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i != 0; ++i)
	{
		glVertex4dv(mBuffer[i].GetGlPointer());
	}
	glEnd();
}
