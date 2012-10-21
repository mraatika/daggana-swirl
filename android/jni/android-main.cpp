#include <jni.h>

#include "../../core/src/dagganaswirl/application/controllers/dagganaapp.h"
#include "../../core/src/dagganaswirl/game/view/gameview.h"

DagganaApp * app = 0;


extern "C" {

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeInit(JNIEnv*  env)
{
	if (!app)
	{
		app = new DagganaApp();
	}
	app->getGameView()->initGL();
}

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeRender(JNIEnv*  env)
{
	if (app)
	{
		app->getGameView()->drawGL();
	}
}

JNIEXPORT void JNICALL Java_fi_dagganaswirl_DagganaRenderer_nativeResize(JNIEnv*  env, jobject  thiz, jint w, jint h)
{
	if (app)
	{
		app->getGameView()->resizeGL(w, h);
	}
}

}