#include "Box.h"
#include <assert.h>
#include <stdio.h>
#include "VG/openvg.h"
#include "png2raw.h"
Box::Box()
{

	png2raw::open("soldier.png");
	//vgCreateImage(VG_sRGB_565, 128, 128, VG_IMAGE_QUALITY_BETTER);
	//vgImageSubData(vg_img, buffer, 256, VG_sRGB_565, 0, 0, 128, 128);
}

Box::~Box()
{
}

void Box::tick(uint32_t delta)
{
	
}

void Box::render()
{
	vgClear(128,128,128,128);
	//vgSetPixels(0, 0, vg_img, 0, 0, 128, 128);
	//vgDrawImage(vg_img);
}
