#include "base_config.h"
#include "wc_eclipse.h"
#include <memory.h>
#include <math.h>

void wcEclipseInitialize(struct wcEclipse *ptr, int size,
						 GLfloat pivotX, GLfloat pivotY,
						 GLfloat maxX, GLfloat maxY)
{
	double radian;

	wcEclipseDestroy(ptr);
	ptr->size = size;
	ptr->px = pivotX;
	ptr->py = pivotY;
	ptr->sizeX = maxX;
	ptr->sizeY = maxY;
	ptr->buffer = (struct wcPt3f*) malloc(ptr->size * 
					sizeof(struct wcPt3f));

	for (int i = 0; i < size; ++i)
	{
		radian = 2 * CMATH_PI * i / (double)size;
		ptr->buffer[i].Set(
				   ptr->px + ptr->sizeX * cos(radian),
				   ptr->py + ptr->sizeY * sin(radian),
				   0.0);
	}
}

void wcEclipseDraw(struct wcEclipse *ptr)
{
	glEnableClientState(GL_VERTEX_ARRAY);

	if (ptr->indexPtr == NULL)
	{
		ptr->indexPtr = (GLushort*) malloc(ptr->size * sizeof(GLushort));
		for (int i = 0; i != ptr->size; ++i)
		{
			ptr->indexPtr[i] = i;
		}
	}

	glVertexPointer(3, GL_FLOAT, 0, ptr->buffer);
	glDrawElements(GL_POLYGON, ptr->size, GL_UNSIGNED_SHORT, ptr->indexPtr);
}

void wcEclipseDestroy(struct wcEclipse *ptr)
{
	if (ptr->buffer != NULL)
	{
		free(ptr->buffer);
		ptr->buffer = NULL;
	}
	if (ptr->indexPtr != NULL)
	{
		free(ptr->indexPtr);
		ptr->indexPtr = NULL;
	}
	ptr->size = 0;
	ptr->sizeX = ptr->sizeY = 0.0F;
}
