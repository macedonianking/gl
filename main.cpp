#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

#include <string>

#include "main_application.h"
#include "quad_test.h"

int main(int argc, char **argv)
{
	struct main_entry_t *ptr;

	QuadTestInitialize();
	ptr = GetMainEntry();
	glutInit(&argc, argv);
	glutInitDisplayMode(ptr->mGLUTMode);
	glutInitWindowPosition(ptr->mWindowPointX, ptr->mWindowPointY);
	glutInitWindowSize(ptr->mWindowSizeX, ptr->mWindowSizeY);

	glutCreateWindow(ptr->mWindowTitle);
	glutDisplayFunc(ptr->mDisplayFunc);
	glutReshapeFunc(ptr->mReshapeFunc);

	ptr->mInitialFunc();
	glutMainLoop();
	ptr->mDestroyFunc();
	
	return 0;
}

