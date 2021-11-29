/**
 *
 *  作者: hm
 *
 *  说明: 同步计数器
 *
 */


#include "latch.h"


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 构造函数
		 *
		 * @param count 计数
		 *
		 */
		CountDownLatch::CountDownLatch(uint32_t count) : _count(count)
		{

		}

		/**
		 *
		 * 等待
		 *
		 */
		void CountDownLatch::Wait()
		{
			std::unique_lock<std::mutex> lock(_mutex);

			_condition.wait(lock, [this]() { return _count == 0; });
		}

		/**
		 *
		 * 触发
		 *
		 * @param count 计数
		 *
		 */
		void CountDownLatch::CountDown(uint32_t count)
		{
			std::unique_lock<std::mutex> lock(_mutex);

			if (_count == 0)
			{
				return;
			}

			if (count < _count)
			{
				_count -= count;

				return;
			}

			_count = 0;

			_condition.notify_all();
		}
	}
}
