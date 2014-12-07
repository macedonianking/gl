#include "cube.h"

void cube_initialize(struct wc_cube_t *ptr, int n)
{
	ptr->buffer[0].Set(0, 0, 0);	
	ptr->buffer[1].Set(n, 0, 0);
	ptr->buffer[2].Set(0, 0, n);
	ptr->buffer[3].Set(n, 0, n);
	ptr->buffer[4].Set(0, n, 0);
	ptr->buffer[5].Set(n, n, 0);
	ptr->buffer[6].Set(0, n, n);
	ptr->buffer[7].Set(n, n, n);
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
