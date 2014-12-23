#include "wc_color.h"

template<>
void WcSetColor<GLdouble>(const WcColorT<GLdouble> &color)
{
	glColor4d(color.r, color.g, color.b, color.a);
}

template<>
void WcSetColor<GLfloat>(const WcColorT<GLfloat> &color)
{
	glColor4d(color.r, color.g, color.b, color.a);
}
