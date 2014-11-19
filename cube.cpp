#include "cube.h"

void cube_initialize(struct wc_cube_t *ptr, int n)
{
	SetWcPoint(ptr->buffer + 0, 0, 0, 0);	
	SetWcPoint(ptr->buffer + 1, n, 0, 0);
	SetWcPoint(ptr->buffer + 2, 0, 0, n);
	SetWcPoint(ptr->buffer + 3, n, 0, n);
	SetWcPoint(ptr->buffer + 4, 0, n, 0);
	SetWcPoint(ptr->buffer + 5, n, n, 0);
	SetWcPoint(ptr->buffer + 6, 0, n, n);
	SetWcPoint(ptr->buffer + 7, n, n, n);
}	

void cube_quad(const struct wc_cube_t *ptr,
			   int n0, int n1, int n2, int n3)
{
	glBegin(GL_POLYGON);
		glVertex2fv((GLfloat*)(ptr->buffer + n0));
		glVertex2fv((GLfloat*)(ptr->buffer + n1));
		glVertex2fv((GLfloat*)(ptr->buffer + n2));
		glVertex2fv((GLfloat*)(ptr->buffer + n3));
	glEnd();	
}
