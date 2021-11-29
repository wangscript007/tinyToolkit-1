#ifndef __UTIL__LATCH__H__
#define __UTIL__LATCH__H__


/**
 *
 *  作者: hm
 *
 *  说明: 同步计数器
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <mutex>
#include <cstdint>
#include <condition_variable>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API CountDownLatch
		{
		public:
			/**
			 *
			 * 构造函数
			 *
			 * @param count 计数
			 *
			 */
			explicit CountDownLatch(uint32_t count);

			/**
			 *
			 * 等待
			 *
			 */
			void Wait();

			/**
			 *
			 * 触发
			 *
			 * @param count 计数
			 *
			 */
			void CountDown(uint32_t count = 1);

		private:
			uint32_t _count{ 0 };

			std::mutex _mutex{ };

			std::condition_variable _condition{ };
		};
	}
}


#endif // __UTIL__LATCH__H__
