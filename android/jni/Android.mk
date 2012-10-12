LOCAL_PATH := $(call my-dir)
SRC_PATH := ../../core/src/demo

include $(CLEAR_VARS)

LOCAL_MODULE := sanangeles

LOCAL_CFLAGS := -DANDROID_NDK \
                -DDISABLE_IMPORTGL

LOCAL_SRC_FILES := \
    $(SRC_PATH)/importgl.c \
    $(SRC_PATH)/demo.c \
    $(SRC_PATH)/app-android.c \

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)
