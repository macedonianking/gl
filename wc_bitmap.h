#ifndef WC_BITMAP_H
#define WC_BITMAP_H

#include "base_config.h"

struct wc_bitmap_t
{
	GLsizei	width;
	GLsizei	height;
	GLfloat	originX;
	GLfloat	originY;
	GLubyte	*bitmap;
	GLsizei	bitmap_size;
	GLenum	mode_name;
	GLint	mode_value;
};

struct wc_bitmap_t *wc_bitmap_new(GLsizei w, GLsizei h);
void				wc_bitmap_create(struct wc_bitmap_t *ptr,
									 GLsizei w, GLsizei h);
void				wc_bitmap_destroy(struct wc_bitmap_t* ptr);
void				wc_bitmap_delete(struct wc_bitmap_t *ptr);

void				wc_draw_bitmap(struct wc_bitmap_t *bitmap,
								   GLfloat rasterX,
								   GLfloat rasterY);

#endif // WC_BITMAP_H
