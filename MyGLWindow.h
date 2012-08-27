#ifndef MYGLWINDOW_H
#define MYGLWINDOW_H
#include "EGLWindow.h"
#include "Box.h"
class MyGLWindow : public EGLWindow
{
public:
	MyGLWindow(EGLConfigBuilder* configBuilder=0);
	~MyGLWindow();
	virtual void paintGL();
protected:
	virtual void initializeGL();
private:
	Box* box;
};
#endif /* MYGLWINDOW_H */
