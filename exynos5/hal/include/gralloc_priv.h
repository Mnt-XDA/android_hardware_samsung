/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef GRALLOC_PRIV_H_
#define GRALLOC_PRIV_H_

#include <stdint.h>
#include <limits.h>
#include <sys/cdefs.h>
#include <hardware/gralloc.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

#include <cutils/native_handle.h>

#include <linux/fb.h>

/*****************************************************************************/

/*****************************************************************************/

#ifdef __cplusplus
struct IMG_native_handle_t : public native_handle {
#else
struct IMG_native_handle_t {
    struct native_handle nativeHandle;
    /*
     * int version;
     * int numFds;
     * int numInts;
     * int data[0];
     */
#endif
    int fd;
    int fd1;
    int fd2;
    int var28;
    int var32;
    int var36;
    int var40;
    int var44;
    int var48;
    int var52;
    int format;
    int var64;
    int var68;
    int var72;
    int var76;
    int var80;
    int stride;
    int vstride;

#ifdef __cplusplus
    static int validate(const native_handle* h) {
        const IMG_native_handle_t* hnd = (const IMG_native_handle_t*)h;
        if (h == NULL || (h && h->usage & 0xCBE84CC))
        {
            ALOGE("invalid gralloc handle (at %p)", reinterpret_cast<void *>(const_cast<native_handle *>(h)));
            return -EINVAL;
        }
        return 0;
    }

    static IMG_native_handle_t* dynamicCast(const native_handle* in)
    {
        if (validate(in) == 0)
            return (IMG_native_handle_t*) in;

        return NULL;
    }

#endif
};

#endif /* GRALLOC_PRIV_H_ */
