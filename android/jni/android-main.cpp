#include <jni.h>

#include "../../core/src/dagganaswirl/game/view/gameview.h"

extern void appInit();
extern void appRender();
extern int importGLInit();
GameView * gameView;

void appInit()
{
	gameView = new GameView();
	gameView->initGL();
}

void appRender()
{
	gameView->drawGL();
}


void Java_fi_dagganaswirl_DagganaRenderer_nativeInit(JNIEnv*  env)
{
	appInit();
}
void Java_fi_dagganaswirl_DagganaRenderer_nativeRender(JNIEnv*  env)
{
}
void Java_fi_dagganaswirl_DagganaRenderer_nativeResize(JNIEnv*  env, jobject  thiz, jint w, jint h)
{
	appRender();
}
