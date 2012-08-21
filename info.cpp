#include <iostream>
#include <EGL/egl.h>
#include <assert.h>

int main(int argc, char* argv[])
{
	EGLDisplay display;
	display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	assert(display != EGL_NO_DISPLAY);

	int major;
	int minor;
	EGLBoolean result;
	result = eglInitialize(display, &major, &minor);
	assert(result != EGL_FALSE);
	std::cout << "Major version " << major << " minor " << minor << std::endl;

	EGLint numConfigs;
	result = eglGetConfigs(display, NULL, 0, &numConfigs);
	assert(result != EGL_FALSE);
	std::cout << "number of configs found " << numConfigs << std::endl;
	
	EGLConfig* configs = new EGLConfig[numConfigs];
	result=eglGetConfigs(display, configs, numConfigs, &numConfigs);
	assert(result != EGL_FALSE);

	EGLint value;
	for(int i=0; i<numConfigs; ++i)
	{
		std::cout << std::endl;
		std::cout<<"Config #"<<i<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_BUFFER_SIZE,&value);
		std::cout<<"Buffer Size "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_RED_SIZE,&value);
		std::cout<<"Red Size "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_GREEN_SIZE,&value);
		std::cout<<"Green Size "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_BLUE_SIZE,&value);
		std::cout<<"Blue Size "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_ALPHA_SIZE,&value);
		std::cout<<"Alpha Size "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_CONFIG_CAVEAT,&value);
		switch(value)
		{
			case  EGL_NONE : std::cout<<"EGL_CONFIG_CAVEAT EGL_NONE\n"; break;
			case  EGL_SLOW_CONFIG : std::cout<<"EGL_CONFIG_CAVEAT EGL_SLOW_CONFIG\n"; break;
		}
		eglGetConfigAttrib(display,configs[i],EGL_CONFIG_ID,&value);
		std::cout<<"Config ID "<<value<<"\n";

		eglGetConfigAttrib(display,configs[i],EGL_DEPTH_SIZE,&value);
		std::cout<<"Depth size "<<value<<"\n";

		eglGetConfigAttrib(display,configs[i],EGL_MAX_PBUFFER_WIDTH,&value);
		std::cout<<"Max pbuffer width "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_MAX_PBUFFER_HEIGHT,&value);
		std::cout<<"Max pbuffer height "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_MAX_PBUFFER_PIXELS,&value);
		std::cout<<"Max pbuffer pixels "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_NATIVE_RENDERABLE,&value);
		std::cout<<"Native renderable "<<std::string(value ? "true" : "false")<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_NATIVE_VISUAL_ID,&value);
		std::cout<<"Native visual ID "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_NATIVE_VISUAL_TYPE,&value);
		std::cout<<"Native visual type "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_SAMPLE_BUFFERS,&value);
		std::cout<<"Sample Buffers "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_SAMPLES,&value);
		std::cout<<"Samples "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_SURFACE_TYPE,&value);
		std::cout<<"Surface type "<<value<<"\n";
		eglGetConfigAttrib(display,configs[i],EGL_TRANSPARENT_TYPE,&value);
	}

	delete[] configs;
	
	std::cout << "Hello, World!" << std::endl;
	return 0;
}
