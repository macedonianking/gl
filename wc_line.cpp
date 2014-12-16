#include "wc_line.h"

template<>
void WcLineT<GLint>::Draw()
{
	glBegin(GL_LINES);
	glVertex4iv(mFmPoint.GetGlPointer());
	glVertex4iv(mToPoint.GetGlPointer());
	glEnd();
}

template<>
void WcLineT<GLfloat>::Draw()
{
	glBegin(GL_LINES);
	glVertex4fv(mFmPoint.GetGlPointer());
	glVertex4fv(mToPoint.GetGlPointer());
	glEnd();
}

template<>
void WcLineT<GLdouble>::Draw()
{
	glBegin(GL_LINES);
	glVertex4dv(mFmPoint.GetGlPointer());
	glVertex4dv(mToPoint.GetGlPointer());
	glEnd();
}
