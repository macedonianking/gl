#ifndef WC_COLOR_H
#define WC_COLOR_H

#define WC_COLOR_WHITE	wcColor(1.0F, 1.0F, 1.0F, 1.0F)
#define WC_COLOR_RED	wcColor(1.0F, 0.0F, 0.0F, 1.0F)
#define WC_COLOR_GREEN	wcColor(0.0F, 1.0F, 0.0F, 1.0F)
#define WC_COLOR_BLUE	wcColor(0.0F, 0.0F, 1.0F, 1.0F)
#define WC_COLOR_BLACK	wcColor(0.0F, 0.0F, 0.0F, 1.0F)

class wcColor
{
public:
	GLfloat	r;
	GLfloat g;
	GLfloat b;
	GLfloat a;

	wcColor()
		: r(1.0F),
		  g(1.0F),
		  b(1.0F),
		  a(1.0F)
	{
	}

	wcColor(GLfloat r, GLfloat g, GLfloat b)
		: r(r),
	      g(g),
		  b(b),
		  a(1.0F)	  
	{
	}

	wcColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
		: r(r),
	      g(g),
		  b(b),
		  a(a)	  
	{
	}
};

static struct wcColor getWcColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	struct wcColor color;
	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return color;
}

static void setWcColor(struct wcColor* ptr, GLfloat r, GLfloat g, GLfloat b,
					   GLfloat a)
{
	ptr->r = r;
	ptr->g = g;
	ptr->b = b;
	ptr->a = a;
}

#endif