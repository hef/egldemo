env = Environment(
		CPPPATH=['/opt/vc/include',
			'/opt/vc/include/interface/vcos/pthreads/' ],
		LIBPATH=['/opt/vc/lib'],
		LIBS=['GLESv2',
			'png',
			'EGL'],
		CXXFLAGS=['-g'])
env.Decider("MD5-timestamp")
env.Program('main',
		[
			'main.cpp',
			'EGLConfigBuilder.cpp',
			'EGLWindow.cpp',
			'MyGLWindow.cpp',
			'Box.cpp',
			'png2raw.cpp'
		])
