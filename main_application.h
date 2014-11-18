#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

typedef void (*GLUTDisplayFunc)();
typedef void (*GLUTReshapeFunc)(int, int);
typedef void (*GLUTInitialFunc)();
typedef void (*GLUTDestroyFunc)();

struct main_entry_t
{
	int			mGLUTMode;
	const char*	mWindowTitle;
	int			mWindowPointX;
	int			mWindowPointY;
	int			mWindowSizeX;
	int			mWindowSizeY;
	GLUTDisplayFunc		mDisplayFunc;
	GLUTReshapeFunc		mReshapeFunc;
	GLUTInitialFunc		mInitialFunc;
	GLUTDestroyFunc		mDestroyFunc;
};

main_entry_t	*GetMainEntry();
void			SetMainEntry(main_entry_t *ptr);

void			ResetDefaultMainEntry();

#endif 
