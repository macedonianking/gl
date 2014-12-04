#include "wc_rect.h"

#include <iostream>

#include "base_config.h"

void wcRectF::Draw(GLenum mode)
{
	glBegin(mode);
		glVertex3f(l, b, 0.0F);
		glVertex3f(r, b, 0.0F);
		glVertex3f(r, t, 0.0F);
		glVertex3f(l, t, 0.0F);
	glEnd();
}

wcRectF wcRectF::FromXYWH(GLfloat x, GLfloat y, GLfloat w, GLfloat h)
{
	return wcRectF(x, y, x + w, y + h);
}

wcRectF wcRectF::FromLBRT(GLfloat l, GLfloat b, GLfloat r, GLfloat t)
{
	return wcRectF(l, b, r, t);
}
