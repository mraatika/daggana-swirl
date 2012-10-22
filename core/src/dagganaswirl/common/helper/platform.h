#pragma once
 
#ifdef DAGGANA_IOS
    #import <OpenGLES/ES1/gl.h>
    #define glClearDepth glClearDepthf
    #define glOrtho glOrthof
#endif

#ifdef DAGGANA_OS_X
	#include <OpenGL/gl.h>
#endif

#ifdef ANDROID
	#include <GLES/gl.h>
	#define glClearDepth glClearDepthf
    #define glOrtho glOrthof
#endif