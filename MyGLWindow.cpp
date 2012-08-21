#include "MyGLWindow.h"
#include "GLES2/gl2.h"

MyGLWindow::MyGLWindow(EGLConfigBuilder* configBuilder)
	: EGLWindow(configBuilder)
{
	srand(time(NULL));
}

MyGLWindow::~MyGLWindow()
{

}

void MyGLWindow::initializeGL()
{
	glClearColor(1,1,1,1);
}

void MyGLWindow::paintGL()
{
	float r=(float)rand()/(float)RAND_MAX;
	float g=(float)rand()/(float)RAND_MAX;
	float b=(float)rand()/(float)RAND_MAX;
	glClearColor(r,g,b,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	swapBuffers();
}
