#ifndef WC_COLOR_H
#define WC_COLOR_H

struct wcColor
{
	GLfloat	r;
	GLfloat g;
	GLfloat b;
	GLfloat a;
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
