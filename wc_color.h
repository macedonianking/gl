#ifndef WC_COLOR_H
#define WC_COLOR_H

#include "base_config.h"

#define WC_COLOR_WHITE	WcColorT<GLfloat>(1, 1, 1, 1)
#define WC_COLOR_RED	WcColorT<GLfloat>(1, 0, 0, 1)
#define WC_COLOR_GREEN	WcColorT<GLfloat>(0, 1, 0, 1)
#define WC_COLOR_BLUE	WcColorT<GLfloat>(0, 0, 1, 1)
#define WC_COLOR_BLACK	WcColorT<GLfloat>(0, 0, 0, 1)
#define WC_COLOR_YELLOW	WcColorT<GLfloat>(1, 1, 0, 1)

template<typename Tp>
class WcColorT
{
public:
	Tp	r;
	Tp	g;
	Tp	b;
	Tp	a;

	WcColorT()
		: r(1),
		  g(1),
		  b(1),
		  a(1)
	{
	}

	WcColorT(Tp r, Tp g, Tp b)
		: r(r),
	      g(g),
		  b(b),
		  a(1)	  
	{
	}

	WcColorT(Tp r, Tp g, Tp b, Tp a)
		: r(r),
	      g(g),
		  b(b),
		  a(a)	  
	{
	}

	void Set(Tp r, Tp g, Tp b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = 1;
	}

	void Set(Tp r, Tp g, Tp b, Tp a)
	{
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	const Tp *GetGlPointer() const
	{
		return &r;	
	}

	Tp *GetGlPointer()
	{
		return &r;
	}
};

typedef WcColorT<GLdouble>	WcColorD;
typedef WcColorT<GLfloat>	WcColorF;

template<typename Tp>
void WcSetColor(const WcColorT<Tp> &color)
{
	std::cout << "WcSetColor default implementation" << std::endl;
}

#endif
