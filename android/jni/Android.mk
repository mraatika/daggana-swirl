LOCAL_PATH := $(call my-dir)
SRC_PATH := ../../core/src/demo
DAGGANA_SRC_PATH := ../../core/src/dagganaswirl

include $(CLEAR_VARS)

LOCAL_MODULE := sanangeles

LOCAL_CFLAGS := -DANDROID_NDK \
                -DDISABLE_IMPORTGL

LOCAL_SRC_FILES := \
    $(SRC_PATH)/importgl.c \
    $(SRC_PATH)/demo.c \
    $(SRC_PATH)/app-android.c \
    $(DAGGANA_SRC_PATH)/scorecounter/scorecounter.cpp \
    $(DAGGANA_SRC_PATH)/game/model/game.cpp \
    $(DAGGANA_SRC_PATH)/gameboard/model/gameboard.cpp \
    $(DAGGANA_SRC_PATH)/selection/model/selection.cpp \
    $(DAGGANA_SRC_PATH)/gameclock/model/gameclock.cpp \

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_EXECUTABLE)