#include <jni.h>

#include "../../core/src/dagganaswirl/application/controllers/dagganaapp.h"

DagganaApp * app = 0;


extern "C" {

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeInit(JNIEnv*  env, jobject  thiz, jint w, jint h)
{
	if (!app)
	{
		app = new DagganaApp(w, h);
	}
}

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeRender(JNIEnv*  env)
{
	if (app)
	{
		app->draw();
	}
}

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeResize(JNIEnv*  env, jobject  thiz, jint w, jint h)
{
	if (app)
	{
		app->resize(w, h);
	}
}

}