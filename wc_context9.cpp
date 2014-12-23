#include "wc_context9.h"

#include "wc_matrix.h"

WcContext9::WcContext9()
{
	mTriangle.SetPoints(WcPoint4F(-50.0, -25.0), 
					    WcPoint4F(50.0, -25.0), 
					    WcPoint4F(0, 25.0));
	mTriangle.Offset(50, 50, 0);
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
	WcPoint4F cp;

	cp = mTriangle[2];
	WcContext::OnDraw();

	WcSetColor(WC_COLOR_RED);
	glPushMatrix();
	mTriangle.Draw();
	glPopMatrix();

	WcSetColor(WC_COLOR_BLUE);
	glPushMatrix();
	glTranslatef(cp.x, cp.y, cp.z);
	glRotatef(180, 0, 0, 1);
	glTranslatef(-cp.x, -cp.y, -cp.z);
	mTriangle.Draw();
	glPopMatrix();


}
