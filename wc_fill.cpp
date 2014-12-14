#include "wc_fill.h"

#include "base_config.h"
#include "wc_point.h"
#include "wc_color.h"

static wcPt3f	gTriangleVertices[4];
static wcColor	gTriangleColors[4];
static bool		gInitialized = false;

static void checkInitialize()
{
	if (gInitialized)
	{
		return;	
	}

	gTriangleVertices[0].Set(50.0F, 50.0F, 0.0F);
	gTriangleVertices[1].Set(150.0F, 50.0F, 0.0F);
	gTriangleVertices[2].Set(150.0F, 150.0F, 0.0F);
	gTriangleVertices[3].Set(50.0F, 150.0F, 0.0F);
	gTriangleColors[0].Set(0.0F, 0.0F, 1.0F, 0.0F);
	gTriangleColors[1].Set(1.0F, 0.0F, 0.0F, 0.0F);
	gTriangleColors[2].Set(0.0F, 1.0F, 0.0F, 0.0F);
	gTriangleColors[3].Set(1.0F, 1.0F, 0.0F, 0.0F);
	
	gInitialized = true;
}

void wcFillDraw()
{
	checkInitialize();
}
