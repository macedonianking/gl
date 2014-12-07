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

	wcPt3f(GLfloat valueX, GLfloat valueY)
		: x(valueX),
		  y(valueY),
		  z(0.0F)
	{
	}

	void Set(GLfloat x, GLfloat y, GLfloat z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
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

#endif
