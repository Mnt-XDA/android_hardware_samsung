#
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

ifeq ($(TARGET_BOARD_PLATFORM),exynos5)

exynos5_dirs := \
	libcodec \
	libion_exynos \
	libgscaler \
	librotator \
	libswconverter \
	libhwcService \
	libkeymaster \
	libsecurepath \
	libcec \

exynos5_dirs += \
	libstagefrighthw \
	libcsc \
	libv4l2 \
	libexynosutils \
	libfimg4x

exynos5_dirs += \
	openmax

exynos5_dirs += \
	mobicore

exynos5_dirs += \
	libhwc

include $(call all-named-subdir-makefiles,$(exynos5_dirs))

endif
