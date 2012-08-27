#include "EGLWindow.h"
#include <EGL/egl.h>
#include <assert.h>
#include "EGLConfigBuilder.h"

EGLWindow::EGLWindow(EGLConfigBuilder* configBuilder)
	: activeSurface(false)
	, upscale(false)
	, display(0)
	, context(0)
	, surface(0)
	, configBuilder(configBuilder)  
{
	int32_t success = 0;
	success = graphics_get_display_size(0, &width, &height);
	assert(success >= 0);
	maxWidth = width;
	maxHeight = height;
	if(configBuilder == NULL)
	{
		this->configBuilder = new EGLConfigBuilder();
	}
}

void EGLWindow::makeSurface()
{
	makeSurface(0, 0, width, height);
}

void EGLWindow::setScreen(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	destroySurface();
	makeSurface(x, y, w, h);
}


///@todo I don't like the code quality of this method
void EGLWindow::makeSurface(uint32_t x, uint32_t y, uint32_t w, uint32_t h)
{
	EGLBoolean result;

	static EGL_DISPMANX_WINDOW_T nativeWindow;
	VC_RECT_T dstRect;
	VC_RECT_T srcRect;

	static const EGLint contextAttributes[] =
	{
		EGL_CONTEXT_CLIENT_VERSION, 2,
		EGL_NONE
	};

	display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	assert(display != EGL_FALSE);

	int major;
	int minor;
	result = eglInitialize(display, &major, &minor);
	assert(result != EGL_FALSE);

	configBuilder->chooseConfig(display);
	EGLConfig config = configBuilder->getConfig();

	result = eglBindAPI(EGL_OPENVG_API);
	assert(result != EGL_FALSE);

	//context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttributes);
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
	assert(context != EGL_NO_CONTEXT);
	dstRect.x = x;
	dstRect.y = y;
	if(upscale == false)
	{
		dstRect.width=w;
		dstRect.height = h;
	}
	else
	{
		dstRect.width = maxWidth;
		dstRect.height = maxHeight;
	}
	srcRect.x=0;
	srcRect.y =0;
	srcRect.width = w << 16;
	srcRect.height = h << 16;
	
	dispmanDisplay = vc_dispmanx_display_open(0);
	dispmanUpdate = vc_dispmanx_update_start(0);
	dispmanElement = vc_dispmanx_element_add(dispmanUpdate, dispmanDisplay, 0, &dstRect, 0, &srcRect, DISPMANX_PROTECTION_NONE, 0, 0, DISPMANX_NO_ROTATE);
	nativeWindow.element = dispmanElement;
	nativeWindow.width = w;
	nativeWindow.height = h;
	vc_dispmanx_update_submit_sync(dispmanUpdate);

	surface = eglCreateWindowSurface(display, config, &nativeWindow, NULL);
	assert(surface != EGL_NO_SURFACE);
	result = eglMakeCurrent(display, surface, surface, context);
	assert(result != EGL_FALSE);
	activeSurface=true;
	initializeGL();
}

void EGLWindow::destroySurface()
{
	if(activeSurface == true)
	{
		eglSwapBuffers(display,surface);
		eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
		eglDestroySurface(display,surface);
		eglDestroyContext(display,context);
		eglTerminate(display);
		activeSurface=false;
	}

}

EGLWindow::~EGLWindow()
{
	//glClear( GL_COLOR_BUFFER_BIT);
	destroySurface();
}
void EGLWindow::swapBuffers() const
{
	eglSwapBuffers(display, surface);
}
void EGLWindow::resizeScreen(uint32_t w, uint32_t h)
{
	destroySurface();
	makeSurface(0,0,w,h);
}
