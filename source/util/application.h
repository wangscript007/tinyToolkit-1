#ifndef __UTIL__APPLICATION__H__
#define __UTIL__APPLICATION__H__


/**
 *
 *  作者: hm
 *
 *  说明: 应用信息
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <string>
#include <cstdint>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API Application
		{
		public:
			/**
			 *
			 * 是否存在
			 *
			 * @param pid 序列号
			 *
			 * @return 是否存在
			 *
			 */
			static bool Exist(uint64_t pid);

			/**
			 *
			 * 是否存在
			 *
			 * @param name 名称
			 *
			 * @return 是否存在
			 *
			 */
			static bool Exist(const std::string & name);

			/**
			 *
			 * 设置线程名称
			 *
			 * @param name 名称
			 *
			 * @return 是否设置成功
			 *
			 */
			static bool SetThreadName(const std::string & name);

			/**
			 *
			 * 线程序列号
			 *
			 * @return 线程序列号
			 *
			 */
			static uint64_t ThreadID();

			/**
			 *
			 * 进程序列号
			 *
			 * @return 进程序列号
			 *
			 */
			static uint64_t ProcessID();

			/**
			 *
			 * 占用内存
			 *
			 * @param pid 序列号
			 *
			 * @return 占用内存
			 *
			 */
			static std::size_t UsedMemory(uint64_t pid);

			/**
			 *
			 * 名称
			 *
			 * @return 名称
			 *
			 */
			static std::string Name();

			/**
			 *
			 * 路径
			 *
			 * @return 路径
			 *
			 */
			static std::string Path();

			/**
			 *
			 * 编译时间
			 *
			 * @param date 日期
			 * @param time 时间
			 *
			 * @return 编译时间
			 *
			 */
			static std::string CompileTimeString(const char * date = __DATE__, const char * time = __TIME__);
		};
	}
}


#endif // __UTIL__APPLICATION__H__
