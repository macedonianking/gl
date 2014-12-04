#ifndef GL_WC_POINT_H
#define GL_WC_POINT_H

#include "base_config.h"

struct wcPt2f
{
	GLfloat	x;
	GLfloat y;
};

class wcPt3f
{
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;

	wcPt3f()
		: x(0.0F),
		  y(0.0F),
		  z(0.0F)
	{
	}

	wcPt3f(GLfloat valueX, GLfloat valueY)
		: x(valueX),
		  y(valueY),
		  z(0.0F)
	{
	}
};

struct wcPt2d
{
	GLdouble	x;
	GLdouble	y;
};

struct wcPt3d
{
	GLdouble	x;
	GLdouble	y;
	GLdouble	z;
};

template<typename Tp, typename Te>
void SetWcPoint(Tp *ptr, Te x, Te y)
{
	ptr->x = x;
	ptr->y = y;
}

template<typename Tp, typename Te>
void SetWcPoint(Tp *ptr, Te x, Te y, Te z)
{
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
}

template<typename Tp, typename Te>
void setWcPoint(Tp *ptr, Te x, Te y, Te z)
{
	ptr->x = x;
	ptr->y = y;
	ptr->z = z;
}

#endif
