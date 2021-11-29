#ifndef __UTIL__SYSTEM__H__
#define __UTIL__SYSTEM__H__


/**
 *
 *  作者: hm
 *
 *  说明: 系统信息
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
		class TOOLKIT_API System
		{
		public:
			/**
			 *
			 * 是否是大端字节序
			 *
			 * @return 是否是大端字节序
			 *
			 */
			static bool IsBigEndian();

			/**
			 *
			 * 是否是小端字节序
			 *
			 * @return 是否是小端字节序
			 *
			 */
			static bool IsLittleEndian();

			/**
			 *
			 * 设置环境变量
			 *
			 * @param field 字段
			 * @param value 数值
			 *
			 * @return 是否设置成功
			 *
			 */
			static bool SetEnvironment(const char * field, const char * value);

			/**
			 *
			 * 磁盘使用率
			 *
			 * @param disk 磁盘
			 *
			 * @return 磁盘使用率
			 *
			 */
			static double DiskUsage(const char * disk);

			/**
			 *
			 * 内存使用率
			 *
			 * @return 内存使用率
			 *
			 */
			static double MemoryUsage();

			/**
			 *
			 * 内存页大小
			 *
			 * @return 内存页大小
			 *
			 */
			static uint32_t PageSize();

			/**
			 *
			 * 处理器个数
			 *
			 * @return 处理器个数
			 *
			 */
			static uint32_t ProcessorCount();

			/**
			 *
			 * 磁盘大小
			 *
			 * @param disk 磁盘
			 *
			 * @return 磁盘大小
			 *
			 */
			static std::size_t DiskSize(const char * disk);

			/**
			 *
			 * 内存大小
			 *
			 * @return 内存大小
			 *
			 */
			static std::size_t MemorySize();

			/**
			 *
			 * 磁盘已用大小
			 *
			 * @param disk 磁盘
			 *
			 * @return 磁盘已用大小
			 *
			 */
			static std::size_t DiskUsedSize(const char * disk);

			/**
			 *
			 * 磁盘空闲大小
			 *
			 * @param disk 磁盘
			 *
			 * @return 磁盘空闲大小
			 *
			 */
			static std::size_t DiskFreeSize(const char * disk);

			/**
			 *
			 * 内存已用大小
			 *
			 * @return 内存已用大小
			 *
			 */
			static std::size_t MemoryUsedSize();

			/**
			 *
			 * 内存空闲大小
			 *
			 * @return 内存空闲大小
			 *
			 */
			static std::size_t MemoryFreeSize();

			/**
			 *
			 * 用户名
			 *
			 * @return 用户名
			 *
			 */
			static std::string UserName();

			/**
			 *
			 * 环境变量
			 *
			 * @param field 字段
			 *
			 * @return 环境变量
			 *
			 */
			static std::string Environment(const char * field);

			/**
			 *
			 * 计算机名称
			 *
			 * @return 计算机名称
			 *
			 */
			static std::string ComputerName();
		};
	}
}


#endif // __UTIL__SYSTEM__H__
