#include "wc_rect.h"

#include <iostream>

#include "base_config.h"

GLubyte gDrawIndexBuffer[] = {0, 1, 2, 3};

void wcRectFInitilize(struct wcRectF *ptr, const wcPt3f *point,
					  GLfloat w, GLfloat h)
{
	SetWcPoint(ptr->buffer + 0, point->x, point->y, point->z);
	SetWcPoint(ptr->buffer + 1, point->x + w, point->y, point->z);
	SetWcPoint(ptr->buffer + 2, point->x + w, point->y + h, point->z);
	SetWcPoint(ptr->buffer + 3, point->x, point->y + h, point->z);
}

void wcRectFDraw(struct wcRectF *ptr)
{
	std::cout << "wcRectFDraw" << std::endl;
	glVertexPointer(3, GL_FLOAT, 0, ptr->buffer);
	glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, gDrawIndexBuffer);
}
