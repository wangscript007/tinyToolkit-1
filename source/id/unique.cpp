/**
 *
 *  作者: hm
 *
 *  说明: 全局唯一标识码
 *
 */


#include "unique.h"

#include <chrono>


namespace tinyToolkit
{
	namespace id
	{
		/**
		 *
		 * 构造函数
		 *
		 */
		Unique::Unique()
		{
			_context.key.count = 0;
			_context.key.timestamp = static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
		}

		/**
		 *
		 * 生成
		 *
		 * @return 唯一标识码
		 *
		 */
		uint64_t Unique::Generate()
		{
			auto timestamp = static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());

			if (timestamp == _context.key.timestamp)
			{
				++_context.key.count;
			}
			else
			{
				_context.key.count = 0;
				_context.key.timestamp = timestamp;
			}

			return _context.value;
		}
	}
}
