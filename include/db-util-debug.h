/*
 * libslp-db-util
 *
 * Copyright (c) 2000 - 2011 Samsung Electronics Co., Ltd. All rights reserved.
 *
 * Contact: Hakjoo Ko <hakjoo.ko@samsung.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __DBUTIL_DEBUG_H_
#define __DBUTIL_DEBUG_H_
#include <stdio.h>

#define DBUTIL_USING_PLATFORM_DBG
#define DBUTIL_ENABLE_TRACE

#ifdef DBUTIL_USING_PLATFORM_DBG
	#include <dlog.h>
	#ifdef LOG_TAG
		#undef LOG_TAG
	#endif
	#define LOG_TAG "DBUTIL"
#endif

#ifdef DBUTIL_ENABLE_TRACE

	#ifdef DBUTIL_USING_PLATFORM_DBG

		#define DBUTIL_TRACE_DEBUG LOGD
		#define DBUTIL_TRACE_WARNING LOGW
		#define DBUTIL_TRACE_ERROR LOGE

	#else

		#define DBUTIL_TRACE_DEBUG(fmt, arg...) \
			do {\
				fprintf(stderr,"[DBUTIL]\033[0;32mDEBUG: " fmt "\033[0m\t%s:%d\n", ##arg, strrchr(__FILE__, '/')+1, __LINE__);\
			}while(0);

		#define DBUTIL_TRACE_WARNING(fmt, arg...) \
			do {\
				fprintf(stderr,"[DBUTIL]\033[0;33mWARRING: " fmt "\033[0m\t%s:%d\n", ##arg, strrchr(__FILE__, '/')+1, __LINE__);\
			}while(0);

		#define DBUTIL_TRACE_ERROR(fmt, arg...) \
			do {\
				fprintf(stderr, "[DBUTIL]\033[0;31mERROR: " fmt "\033[0m\t%s:%d\n", ##arg, strrchr(__FILE__, '/')+1, __LINE__);\
			}while(0);

	#endif

#else

	#define DBUTIL_TRACE_DEBUG(fmt, arg...) 
	#define DBUTIL_TRACE_WARNING(fmt, arg...)
	#define DBUTIL_TRACE_ERROR(fmt, arg...)
	
#endif
#endif /* __DBUTIL_DEBUG_H_ */

