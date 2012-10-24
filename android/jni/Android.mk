LOCAL_PATH := $(call my-dir)
SRC_PATH := ../../core/src/dagganaswirl

include $(CLEAR_VARS)

LOCAL_MODULE := dagganaswirl

LOCAL_SRC_FILES := \
	android-main.cpp \
    $(SRC_PATH)/scorecounter/scorecounter.cpp \
    $(SRC_PATH)/game/model/game.cpp \
    $(SRC_PATH)/gameboard/model/gameboard.cpp \
    $(SRC_PATH)/selection/model/selection.cpp \
    $(SRC_PATH)/gameclock/model/gameclock.cpp \
    $(SRC_PATH)/game/view/gameview.cpp \
    $(SRC_PATH)/button/view/buttonview.cpp \
    $(SRC_PATH)/gameboard/view/boardview.cpp \
    $(SRC_PATH)/gameclock/view/clockview.cpp \
    $(SRC_PATH)/scorecounter/view/scoreview.cpp \
    $(SRC_PATH)/application/controllers/dagganaapp.cpp \

LOCAL_LDLIBS := -lGLESv1_CM -ldl -llog

include $(BUILD_SHARED_LIBRARY)