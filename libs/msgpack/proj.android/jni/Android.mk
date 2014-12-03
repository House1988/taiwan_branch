LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := msgpack
LOCAL_MODULE_FILENAME := libmsgpack
LOCAL_CFLAGS  := -O2
LOCAL_CPPFLAGS  := -O2
LOCAL_SRC_FILES := \
../objectc.c\
../object.cpp\
../unpack.c\
../version.c\
../vrefbuffer.c\
../zone.c

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/../

LOCAL_C_INCLUDES := $(LOCAL_PATH)/..

include $(BUILD_STATIC_LIBRARY)
