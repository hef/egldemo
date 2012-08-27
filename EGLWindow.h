#ifndef EGLWINDOW_H
#define EGLWINDOW_H
#include <EGL/egl.h>
class EGLConfigBuilder;
class EGLWindow
{
public:
	EGLWindow(EGLConfigBuilder *config=NULL);
	~EGLWindow();
	virtual void paintGL()=0;
	void swapBuffers() const;
	void resizeScreen(uint32_t width, uint32_t height);
	void setScreen(uint32_t x, uint32_t y, uint32_t w, uint32_t height);
	void destroySurface();
	inline uint32_t getMaxWidth() const {return maxWidth;}
	inline uint32_t getWidth() const {return width;}
	inline uint32_t getMaxHeight() const {return maxHeight;}
	inline uint32_t getHeight() const {return height;}
	inline void setUpscale(bool upscale){this->upscale = upscale;}
protected:
	virtual void initializeGL()=0;
	void makeSurface();
	uint32_t width;
	uint32_t height;
	uint32_t maxWidth;
	uint32_t maxHeight;
	EGLDisplay display;
	EGLSurface surface;
	EGLContext context;
	EGLConfigBuilder* configBuilder;
	DISPMANX_ELEMENT_HANDLE_T dispmanElement;
	DISPMANX_ELEMENT_HANDLE_T dispmanDisplay;
	DISPMANX_ELEMENT_HANDLE_T dispmanUpdate;
private:
	void makeSurface(uint32_t x, uint32_t y, uint32_t w, uint32_t h);
	bool activeSurface;
	bool upscale;
};
#endif //EGLWINDOW_H
