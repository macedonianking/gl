#ifndef GL_WC_MATH_H
#define GL_WC_MATH_H

#include <math.h>

#ifndef MATH_PI
#define MATH_PI	3.1415926
#endif


static inline double ToRadian(double angle)
{
	return MATH_PI * angle / 180.0; 
}

static inline double ToAngle(double angle)
{
	return angle * 180.0 / MATH_PI;	
}

#endif // GL_WC_MATH_H
