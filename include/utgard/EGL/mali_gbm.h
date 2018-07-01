/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from Rockchip.
 * Copyright (c) 2017 FUZHOU ROCKCHIP ELECTRONICS CO., LTD. ("Rockchip").
 * 	http://www.rock-chips.com
 * 		ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from Rockchip.
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/**
 * @file mali_gbm.h
 * @brief A window type for the gbm platform (used by egl and tests)
 */

#ifndef _MALI_GBM_H_
#define _MALI_GBM_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GBM_MAX_NUM_BO
#define GBM_MAX_NUM_BO 3
#endif

typedef struct gbm_device
{
	struct gbm_device *(*is_gbm_device)(int);
	int32_t fd;
	int32_t refcnt;
	void *mutex;
} gbm_device;

typedef struct gbm_bo
{
	struct gbm_device *device;
	uint32_t width;
	uint32_t height;
	uint32_t bpp;
	uint32_t pitch;
	uint32_t format;
	uint32_t flags;
	uint32_t status;
	uintptr_t handle;
	int32_t fd;
	int32_t refcnt;
	void *map;
	void *mutex;
	void *lock;
	void *user_data;
	void (*destroy_user_data)(struct gbm_bo *, void *);
} gbm_bo;

typedef struct gbm_surface
{
	struct gbm_device *device;
	uint32_t width;
	uint32_t height;
	uint32_t gbm_format;
	uint32_t gbm_flags;
	struct gbm_bo *bo[GBM_MAX_NUM_BO];
	uint32_t current;
	int32_t refcnt;
	void *mutex;
} gbm_surface;

#ifdef __cplusplus
}
#endif

#endif

