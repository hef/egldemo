#include <EGL/egl.h>
#include <map>

class EGLConfigBuilder
{
	public:
	EGLConfigBuilder();
	~EGLConfigBuilder();
	void setAttribute(EGLint attribute, EGLint value);
	void setRGBA(EGLint r, EGLint g, EGLint b, EGLint a);
	void setDepth(EGLint d); 
	void setSurface(EGLint s);
	void chooseConfig(EGLDisplay display);
	inline EGLConfig getConfig() {return config;};
	private:
		std::map<EGLint,EGLint> attributes;
		EGLConfig config;	
};
