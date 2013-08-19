LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := \
	dec/ExynosVideoDecoder.c \
	enc/ExynosVideoEncoder.c

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/include \
	$(TOP)/hardware/samsung/$(TARGET_BOARD_PLATFORM)/hal/include

ifeq ($(BOARD_USE_KHRONOS_OMX_HEADER), true)
LOCAL_C_INCLUDES += $(TOP)/hardware/samsung/$(TARGET_BOARD_PLATFORM)/hal/openmax/include/khronos
else
LOCAL_C_INCLUDES += $(TOP)/frameworks/native/include/media/openmax
endif

LOCAL_MODULE := libExynosVideoApi
LOCAL_MODULE_TAGS := optional
LOCAL_PRELINK_MODULE := false
LOCAL_ARM_MODE := arm

include $(BUILD_STATIC_LIBRARY)
