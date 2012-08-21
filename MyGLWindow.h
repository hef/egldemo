#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H
#include "EGLWindow.h"
class MyGLWindow : public EGLWindow
{
public:
	MyGLWindow(EGLConfigBuilder* configBuilder=0);
	~MyGLWindow();
	virtual void paintGL();
protected:
	virtual void initializeGL();
};
#endif /* MYGLWINDOW_H */
