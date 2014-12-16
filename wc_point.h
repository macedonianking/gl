#ifndef GL_WC_POINT_H
#define GL_WC_POINT_H

#include "base_config.h"

class wcPt2f
{
public:
	wcPt2f()
		:x(0.0F),
		 y(0.0F)
	{
	}

	wcPt2f(GLfloat vx, GLfloat vy)
		:x(vx),
		 y(vy)
	{
	}

	void Set(GLfloat x, GLfloat y)
	{
		this->x = x;
		this->y = y;
	}

	const GLfloat *GetGlPointer() const
	{
		return &x;
	}

	GLfloat *GetGlPointer()
	{
		return &x;
	}
public:
	GLfloat	x;
	GLfloat y;
};

class wcPt3f
{
public:
	wcPt3f()
		: x(0.0F),
		  y(0.0F),
		  z(0.0F)
	{
	}

	wcPt3f(GLfloat valueX, GLfloat valueY):
		x(valueX),
		y(valueY),
		z(0.0F)
	{
	}

	wcPt3f(GLfloat valueX, GLfloat valueY, GLfloat valueZ)
		: x(valueX),
		  y(valueY),
		  z(valueZ)
	{
	}

	void Set(GLfloat x, GLfloat y, GLfloat z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	const GLfloat *GetGlPointer() const
	{
		return &x;
	}

	GLfloat *GetGlPointer()
	{
		return &x;
	}
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
};

class wcPt2d
{
public:
	wcPt2d()
		:x(0.0),
		 y(0.0)
	{
	}

	wcPt2d(GLdouble x, GLdouble y, GLdouble z) :
		x(x),
		y(y)
	{
	}

	void Set()
	{
		this->x = x;
		this->y = y;
	}

public:
	GLdouble	x;
	GLdouble	y;
};

struct wcPt3d
{
public:
	GLdouble	x;
	GLdouble	y;
	GLdouble	z;
};

template<typename Tp>
class WcPoint4T
{
public:
	WcPoint4T() :
		x(0),
		y(0),
		z(0),
		w(1)
	{
	}

	WcPoint4T(Tp vx, Tp vy) : 
		x(vx),
		y(vy), 
		z(0),
		w(1)
	{
	}

	WcPoint4T(Tp vx, Tp vy, Tp vz) : 
		x(vx),
		y(vy),
		z(vz),
		w(1)
	{
	}

	WcPoint4T(Tp vx, Tp vy, Tp vz, Tp vw) :
		x(vx),
		y(vy),
		z(vz),
		w(vw)
	{
	}

	Tp *GetGlPointer()
	{
		return &x;
	}

	const Tp *GetGlPointer() const
	{
		return &x;
	}
public:
	Tp	x;
	Tp	y;
	Tp	z;
	Tp	w;
};

typedef WcPoint4T<GLfloat>	WcPoint4F;
typedef WcPoint4T<GLdouble>	WcPoint4D;

template<typename Tp, typename Point = WcPoint4T<Tp>>
Point make_point(Tp x, Tp y)
{
	return Point(x, y);
}

template<typename Tp, typename Point = WcPoint4T<Tp>>
Point make_point(Tp x, Tp y, Tp z)
{
	return Point(x, y, z);
}

template<typename Tp, typename Point = WcPoint4T<Tp>>
Point make_point(Tp x, Tp y, Tp z, Tp w)
{
	return Point(x, y, z, w);
}

#endif
