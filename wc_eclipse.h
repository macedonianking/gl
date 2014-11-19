#ifndef GL_WC_ECLIPSE_H
#define GL_WC_ECLIPSE_H

#include "wc_point.h"

struct wcEclipse
{
	struct wcPt3f	*buffer;
	int				size;
	GLfloat			px;
	GLfloat			py;
	GLfloat			sizeX;
	GLfloat			sizeY;
	GLubyte			*indexPtr;
};

void wcEclipseInitialize(struct wcEclipse *ptr, int size,
						 GLfloat pivotX, GLfloat pivotY,
						 GLfloat maxX, GLfloat maxY);

void wcEclipseDraw(struct wcEclipse *ptr);

void wcEclipseDestroy(struct wcEclipse *ptr);

#endif
