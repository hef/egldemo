#ifndef BOX_H
#define BOX_H
#include <EGL/egl.h>
#include <VG/openvg.h>
class Box
{
public:
	Box();
	~Box();
	void tick(uint32_t delta);
	void render();
private:
	uint32_t x;
	uint32_t y;
	VGImage vg_img;
};
#endif /* BOX_H */
