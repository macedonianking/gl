#include "wc_context9.h"

#include "wc_matrix.h"

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
	WcMatrix4F matrix;

	glColor4f(1.0F, 0.0F, 0.0F, 1.0F);
	glPushMatrix();
	glLoadIdentity();
	matrix.SetTranslate(100.0F, 0.0F, 0.0F);
	glLoadMatrixf(matrix.GetGlMatrix());
	mTriangle.Draw();
	glPopMatrix();
}
