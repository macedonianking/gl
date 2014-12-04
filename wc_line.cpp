#include "wc_line.h"

#include "base_config.h"

void wcDrawLine()
{
	glShadeModel(GL_FLAT);
	glBegin(GL_LINES);
		glColor3f(0.0F, 0.0F, 1.0F);
		glVertex2f(50.0F, 50.0F);
		glColor3f(1.0F, 0.0F, 0.0F);
		glVertex2f(250.0F, 250.0F);
	glEnd();
}

void WcLine::Draw()
{
	glBegin(GL_LINES);
		glVertex3fv(reinterpret_cast<GLfloat*>(&mPointFm));
		glVertex3fv(reinterpret_cast<GLfloat*>(&mPointTo));
	glEnd();
}
