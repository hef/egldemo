#include <iostream>
#include "MyGLWindow.h"
#include "bcm_host.h"
#include "EGLConfigBuilder.h"

int main(int argc, char* argv[])
{
	atexit(bcm_host_deinit);
	bcm_host_init();
	EGLConfigBuilder* configBuilder = new EGLConfigBuilder();
	configBuilder->setRGBA(5,6,5,0);
	configBuilder->setDepth(16);
	MyGLWindow win(configBuilder);
	uint32_t w=win.getMaxWidth();
	uint32_t h=win.getMaxHeight();
	win.setUpscale(false);
	win.setScreen(w/4,h/4,w/2,h/2);
	while(true)
	{
		win.paintGL();
		sleep(1);
	}
}
