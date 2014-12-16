#include "wc_context9.h"

WcContext9::WcContext9()
{
	mTriangle.SetPoints(WcPoint4F(-50.0, -25.0), 
					    WcPoint4F(50.0, -25.0), 
					    WcPoint4F(0, 25.0));
}

WcContext9::~WcContext9()
{
}

void WcContext9::SetWindowSize(int w, int h)
{
	WcContext::SetWindowSize(w, h);
}

void WcContext9::OnDraw()
{
	WcContext::OnDraw();

	std::cout << "OnDraw" << std::endl;

	glColor4f(1.0F, 0.0F, 0.0F, 1.0F);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(100, 100);
	glEnd();

	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glEnd();
}
