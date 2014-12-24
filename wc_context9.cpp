#include "wc_context9.h"

#include "wc_matrix.h"

#include <iostream>

#define MSG_HELLO_WORLD	0x0001

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
	mHandler->PostMessage(MSG_HELLO_WORLD);
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

void WcContext9::HandleMessage(WcMessage &msg)
{
	switch(msg.what)
	{
		case MSG_HELLO_WORLD:
			{
				std::cout << "MSG_HELLO_WORLD" << std::endl;
				break;
			}
		default:
			{
				WcContext::HandleMessage(msg);
				break;
			}
	}
}

void WcContext9::HandleClearMessage(WcMessage &msg)
{
	switch(msg.what)
	{
		default: 
			{
				WcContext9::HandleClearMessage(msg);
			}
	}
}
