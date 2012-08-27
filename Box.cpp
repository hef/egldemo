#include "Box.h"
#include <assert.h>
#include <stdio.h>
#include "VG/openvg.h"
Box::Box()
{
	FILE* file = fopen("Lucca_128_128.raw", "rb");
	int size = 128 * 128 * 3;
	void* buffer = malloc(size);
	int bytes_read = fread(buffer, 1, size, file);
	assert(bytes_read == size);
	fclose(file);
	vgCreateImage(VG_sRGB_565, 128, 128, VG_IMAGE_QUALITY_BETTER);
	vgImageSubData(vg_img, buffer, 256, VG_sRGB_565, 0, 0, 128, 128);
	free(buffer);
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
