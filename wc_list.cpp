#include "wc_list.h"

#include "wc_eclipse.h"

void wc_list_test_initial(struct wc_list_t *ptr)
{
	wc_list_initial(ptr, 1);
	if (!wc_list_is_available(ptr))
	{
		return;
	}

	wcEclipse eclispe;
	wcEclipseInitialize(&eclispe, 6, 200, 200, 50, 50);
	wc_list_new_list(ptr->base);
	glBegin(GL_POLYGON);
		for (int i = 0; i < eclispe.size; ++i)
		{
			glVertex3fv(reinterpret_cast<const GLfloat*>(
						eclispe.buffer + i));
		}
	glEnd();
	wc_list_end_list();
}
