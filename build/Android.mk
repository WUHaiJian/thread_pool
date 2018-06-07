LOCAL_PATH := $(call my-dir)
PROJECT_PATH = ..
include $(CLEAR_VARS)

#SRC_FILES := $(wildcard $(PROJECT_PATH)/*.c)
#LOCAL_SRC_FILES := $(SRC_FILES:$(PROJECT_PATH)/%=%)
LOCAL_SRC_FILES := $(PROJECT_PATH)/scpthread.c \
                   $(PROJECT_PATH)/test_scpthread.c

#C_INCLUDES := $(wildcard $(LOCAL_PATH)/../*.h)
#LOCAL_C_INCLUDES := $(C_INCLUDES:$(LOCAL_PATH)/../%=%)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../
#LOCAL_C_INCLUDES += system/core/include/cutils
                    
LOCAL_MODULE := nptl
#LOCAL_SHARED_LIBRARIES := libcutil

include $(BUILD_EXECUTABLE)