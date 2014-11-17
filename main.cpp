#include <stdio.h>
#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>

static void main_initial_func();
static void main_display_func();
static void main_reshape_func(int w, int h);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 200);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("GLDrawLine");
	glutDisplayFunc(&main_display_func);
	glutReshapeFunc(&main_reshape_func);
	
	printf("Hello world\n");
	main_initial_func();
	glutMainLoop();
	
	return 0;
}

void main_initial_func()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0F, 200.0F, 0.0F, 150.0F);

	glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
}

void main_display_func()
{
	printf("main_display_func enter\n");
	glClearColor(1.0F, 1.0F,1.0F, 0.0F);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glFlush();
	printf("main_display_func leave\n");
}

void main_reshape_func(int w, int h)
{
}
