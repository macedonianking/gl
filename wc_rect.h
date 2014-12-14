#ifndef GL_WC_RECT_H
#define GL_WC_RECT_H

#include "wc_point.h"
#include "base_config.h"

class wcRectF
{
public:
	wcRectF()
		: l(0.0F), 
		  b(0.0F),
		  r(0.0F),
		  t(0.0F)
	{
	}

	wcRectF(GLfloat l, GLfloat b, GLfloat r, GLfloat t)
		: l(l),
		  b(b),
		  r(r),
		  t(t)
	{
	}

	void SetLBRT(GLfloat l, GLfloat b, GLfloat r, GLfloat t)
	{
		this->l = l;
		this->b = b;
		this->r = r;
		this->t = t;
	}

	void SetXYWH(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
	{
		this->l = x;
		this->b = y;
		this->r = this->l + w;
		this->t = this->b + h;
	}

	wcRectF &AdjustX()
	{
		if (this->r < this->l)
		{
			GLfloat v = this->r;
			this->r = this->l;
			this->l = v;
		}
		return *this;
	}

	wcRectF &AdjustY()
	{
		if (this->t < this->b)
		{
			GLfloat v = this->t;
			this->t = this->b;
			this->b = v;
		}
		return *this;
	}

	wcRectF &Adjust()
	{
		return this->AdjustX().AdjustY();
	}

	GLfloat Width() const
	{
		return r - l;
	}

	GLfloat Height() const
	{
		return t - b;
	}

	GLfloat GetCenterX() const
	{
		return (l + r) / 2.0F;
	}

	GLfloat GetCenterY() const
	{
		return (b + t) / 2.0F;
	}

	void Draw(GLenum mode);

	static wcRectF FromXYWH(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	static wcRectF FromLBRT(GLfloat l, GLfloat b, GLfloat r, GLfloat t);
public:
	GLfloat	l;
	GLfloat b;	
	GLfloat	r;
	GLfloat	t;
};

#endif
