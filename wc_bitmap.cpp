#include "wc_bitmap.h"

#include <memory.h>

void wc_draw_bitmap(struct wc_bitmap_t *ptr,
					GLfloat rasterX,
					GLfloat rasterY,
					GLfloat offsetX,
					GLfloat offsetY)
{
	glRasterPos2f(rasterX, rasterY);
	glPixelStorei(ptr->mode_name, ptr->mode_value);
	glBitmap(ptr->width, ptr->height, ptr->originX, ptr->originY, 
			 offsetX, offsetY, ptr->bitmap);
}

void wc_bitmap_destroy(struct wc_bitmap_t *ptr)
{
	if (ptr->bitmap)
	{
		free(ptr->bitmap);
		ptr->bitmap = NULL;
	}
	memset(ptr, 0, sizeof(struct wc_bitmap_t));
}

void wc_bitmap_delete(struct wc_bitmap_t *ptr)
{
	wc_bitmap_destroy(ptr);
	free(ptr);
}

void wc_bitmap_create(struct wc_bitmap_t *ptr,
					  GLsizei w, GLsizei h)
{
	int			n;
	
	memset(ptr, 0, sizeof(struct wc_bitmap_t));
	ptr->originX = ptr->originY = 0;
	ptr->width = w;
	ptr->height = h;
	ptr->mode_name = GL_UNPACK_ALIGNMENT;
	ptr->mode_value = 1;
	n = (w + 7) / 8;
	ptr->bitmap = (GLubyte*) malloc(n * h * sizeof(GLubyte));
	memset(ptr->bitmap, 0, n * h * sizeof(GLubyte));
}
