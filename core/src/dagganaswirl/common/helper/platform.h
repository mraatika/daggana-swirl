#pragma once

#define OS_X

#ifdef OS_X
	#include <OpenGL/gl.h>
#endif

#ifdef ANDROID
	#include <GLES/gl.h>
	#define glClearDepth glClearDepthf
    #define glOrtho glOrthof
#endif