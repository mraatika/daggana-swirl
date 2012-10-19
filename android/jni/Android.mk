LOCAL_PATH := $(call my-dir)
SRC_PATH := ../../core/src/demo
DAGGANA_SRC_PATH := ../../core/src/dagganaswirl

include $(CLEAR_VARS)

LOCAL_MODULE := dagganaswirl

LOCAL_CFLAGS := -DANDROID_NDK \
                -DDISABLE_IMPORTGL

LOCAL_SRC_FILES := \
	android-main.cpp \
    $(DAGGANA_SRC_PATH)/scorecounter/scorecounter.cpp \
    $(DAGGANA_SRC_PATH)/game/model/game.cpp \
    $(DAGGANA_SRC_PATH)/gameboard/model/gameboard.cpp \
    $(DAGGANA_SRC_PATH)/selection/model/selection.cpp \
    $(DAGGANA_SRC_PATH)/gameclock/model/gameclock.cpp \
    $(DAGGANA_SRC_PATH)/game/view/gameview.cpp \

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_EXECUTABLE)