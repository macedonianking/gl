#ifndef GL_CUBE_H
#define GL_CUBE_H

#include "base_config.h"
#include "wc_point.h"

#define CUBE_VERTEX_COUNT 8

struct wc_cube_t
{
	struct wcPt3f buffer[CUBE_VERTEX_COUNT];
};

void cube_initialize(struct wc_cube_t *ptr, int n);

void cube_quad(const struct wc_cube_t *ptr, 
			   int n0, int n1, int n2, int n3);

#endif
