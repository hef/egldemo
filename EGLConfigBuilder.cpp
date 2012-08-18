#include "EGLConfigBuilder.h"
#include <assert.h>
#include <vector>
EGLConfigBuilder::EGLConfigBuilder()
{
	attributes[EGL_RED_SIZE]=8;
	attributes[EGL_GREEN_SIZE]=8;
	attributes[EGL_BLUE_SIZE]=8;
	attributes[EGL_ALPHA_SIZE]=8;
	attributes[EGL_SURFACE_TYPE]=EGL_WINDOW_BIT;
}
EGLConfigBuilder::~EGLConfigBuilder()
{

}
void EGLConfigBuilder::setAttribute(EGLint attribute, EGLint value)
{
	assert(attribute >= 0x3020);
	assert(attribute <= 0x3042);
	attributes[attribute]=value;
}
void EGLConfigBuilder::setRGBA(EGLint red, EGLint green, EGLint blue, EGLint alpha)
{
	attributes[EGL_RED_SIZE]=red;
	attributes[EGL_GREEN_SIZE]=green;
	attributes[EGL_BLUE_SIZE]=blue;
	attributes[EGL_ALPHA_SIZE]=alpha;
}
void EGLConfigBuilder::setDepth(EGLint depth)
{
	attributes[EGL_DEPTH_SIZE]=depth;
}
void EGLConfigBuilder::setSurface(EGLint surface)
{
	attributes[EGL_DEPTH_SIZE]=surface;
}

void EGLConfigBuilder::chooseConfig(EGLDisplay display)
{
	std::map<EGLint, EGLint>::const_iterator i;

	std::vector<EGLint> attributeArray;
	for( i = attributes.begin(); i != attributes.end(); ++i)
	{	
		attributeArray.push_back(i->first);
		attributeArray.push_back(i->second);
	}
	attributeArray.push_back(EGL_NONE);

	EGLBoolean result;
	EGLint numConfig;

	result = eglChooseConfig(display, &attributeArray[0], &config, 1, &numConfig);
	assert(result != EGL_FALSE);
}
