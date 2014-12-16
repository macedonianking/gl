#include "wc_rect.h"

template<>
void WcRectT<GLfloat>::Draw(GLenum  mode)
{
	glBegin(mode);	
		glVertex2f(left, bottom);
		glVertex2f(right, bottom);
		glVertex2f(right, top);
		glVertex2f(left, top);
	glEnd();
}

template<>
void WcRectT<GLdouble>::Draw(GLenum  mode)
{
	glBegin(mode);	
		glVertex2d(left, bottom);
		glVertex2d(right, bottom);
		glVertex2d(right, top);
		glVertex2d(left, top);
	glEnd();
}

template<>
void WcRectT<GLint>::Draw(GLenum  mode)
{
	glBegin(mode);	
		glVertex2i(left, bottom);
		glVertex2i(right, bottom);
		glVertex2i(right, top);
		glVertex2i(left, top);
	glEnd();
}
