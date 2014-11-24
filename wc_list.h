#ifndef WC_LIST_H
#define WC_LIST_H

#include "base_config.h"

struct wc_list_t
{
	GLuint		base;
	GLsizei		size;
	GLuint		*call_list;
};

static inline void wc_list_initial(struct wc_list_t *ptr, GLsizei size)
{
	ptr->base = glGenLists(size);
	if (ptr->base == 0)
	{
		ptr->size = 0;
	}
	else
	{
		ptr->size = size;
	}
	ptr->call_list = NULL;
}

static inline void wc_list_release(struct wc_list_t *ptr)
{
	if (ptr->base != 0)
	{
		glDeleteLists(ptr->base, ptr->size);
	}
	if (ptr->call_list)
	{
		free(ptr->call_list);
		ptr->call_list = NULL;
	}
}

static inline bool wc_list_is_available(struct wc_list_t *ptr)
{
	return ptr->base != 0 && ptr->size > 0;
}

static inline void wc_list_new_list(GLint listId)
{
	glNewList(listId, GL_COMPILE);
}

static inline void wc_list_end_list()
{
	glEndList();
}

static inline void wc_list_call_lists(GLsizei offset, GLuint* ptr, 
									  GLsizei size)
{
	glCallLists(size, GL_UNSIGNED_INT, ptr);
}

static inline void wc_list_draw(struct wc_list_t *ptr)
{
	if (ptr->size == 0)
	{
		glCallList(ptr->base);
	}	
	else
	{
		if (NULL == ptr->call_list)
		{
			ptr->call_list = (GLuint*) malloc(ptr->size * sizeof(GLuint));
			for (GLuint i = 0; i < ptr->size; ++i)
			{
				ptr->call_list[i] = i;	
			}
		}
		glCallLists(ptr->size, GL_UNSIGNED_INT, ptr->call_list);
	}
}

void wc_list_test_initial(struct wc_list_t *ptr);

#endif
