#ifndef GL_WC_RECT_H
#define GL_WC_RECT_H

#include <iostream>
#include <sstream>

#include "wc_point.h"
#include "base_config.h"


template<typename Tp>
class WcRectT
{
public:
	WcRectT()
		: left(0), 
		  bottom(0),
		  right(0),
		  top(0)
	{
	}

	WcRectT(Tp lefteft, Tp bottomottom, Tp rightight, Tp topop)
		: left(left),
		  bottom(bottom),
		  right(right),
		  top(top)
	{
	}

	void SetLBRT(Tp left, Tp bottom, Tp right, Tp top)
	{
		this->left = left;
		this->bottom = bottom;
		this->right = right;
		this->top = top;
	}

	void SetXYWH(Tp x, Tp y, Tp w, Tp h)
	{
		this->left = x;
		this->bottom = y;
		this->right = this->left + w;
		this->top = this->bottom + h;
	}

	WcRectT &AdjustX()
	{
		if (this->right < this->left)
		{
			Tp v = this->right;
			this->right = this->left;
			this->left = v;
		}
		return *this;
	}

	WcRectT &AdjustY()
	{
		if (this->top < this->bottom)
		{
			Tp v = this->top;
			this->top = this->bottom;
			this->bottom = v;
		}
		return *this;
	}

	WcRectT &Adjust()
	{
		return this->AdjustX().AdjustY();
	}

	Tp Width() const
	{
		return right - left;
	}

	Tp Height() const
	{
		return this->top - this->bottom;
	}

	Tp GetCenterX() const
	{
		return (this->left + this->right) / 2;
	}

	Tp GetCenterY() const
	{
		return (this->top + this->bottom) / 2;
	}

	std::string ToString() const;
	void Draw(GLenum mode);

	static WcRectT FromXYWH(Tp x, Tp y, Tp w, Tp h);
	static WcRectT FromLBRT(Tp left, Tp bottom, Tp right, Tp top);
public:
	Tp	left;
	Tp	bottom;	
	Tp	right;
	Tp	top;
};

template<typename Tp>
void WcRectT<Tp>::Draw(GLenum mode)
{
}

template<typename Tp>
std::string WcRectT<Tp>::ToString() const
{
	std::stringstream out;
	
	out << "WcRect["
		<< left << ","
		<< bottom << ","
		<< right << ","
		<< top << "]";
	return out.str();
}

template<typename Tp>
WcRectT<Tp> WcRectT<Tp>::FromXYWH(Tp x, Tp y, Tp w, Tp h)
{
	return WcRectT(x, y, x + w, y + h);
}

template<typename Tp>
WcRectT<Tp> WcRectT<Tp>::FromLBRT(Tp left, Tp bottom, Tp right, Tp top)
{
	return WcRectT(left, bottom, right, top);
}

typedef WcRectT<GLint>		WcRectI;	
typedef WcRectT<GLfloat>	WcRectF;
typedef WcRectT<GLdouble>	WcRectD;
#endif
