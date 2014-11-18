#ifndef GL_LOGGING_H
#define GL_LOGGING_H

#include <assert.h>

#ifndef NDEBUG
#define	DASSERT(cond)
#else
#define DASSERT(cond)	assert(cond)
#endif

#endif 
