#ifndef GL_WC_RECT_H
#define GL_WC_RECT_H

#include "wc_point.h"

struct wcRectF
{
	struct wcPt3f buffer[4];
};

void wcRectFInitilize(struct wcRectF *ptr, const wcPt3f *point,
					  GLfloat w, GLfloat h);

void wcRectFDraw(struct wcRectF *ptr);

#endif
