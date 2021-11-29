/**
 *
 *  作者: hm
 *
 *  说明: 系统信息
 *
 */


#include "system.h"

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS
#
#  include <Windows.h>
#
#else
#
#  include <pwd.h>
#  include <unistd.h>
#
#  if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE
#
#    include <sys/mount.h>
#
#    include <mach/mach_host.h>
#
#  else
#
#    include <sys/statfs.h>
#    include <sys/sysinfo.h>
#
#  endif
#
#endif


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 系统磁盘信息
		 *
		 * @param disk 磁盘
		 * @param total 总体内存大小
		 * @param avail 空闲内存大小
		 *
		 * @return 是否获取成功
		 *
		 */
		static bool SystemDiskInfo(const char * disk, std::size_t * total, std::size_t * avail)
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			ULARGE_INTEGER totalBytes{ 0 };
			ULARGE_INTEGER availBytes{ 0 };

			if (::GetDiskFreeSpaceEx(disk, nullptr, &totalBytes, &availBytes) == FALSE)
			{
				return false;
			}

			if (total)
			{
				*total = static_cast<std::size_t>(totalBytes.QuadPart);
			}

			if (avail)
			{
				*avail = static_cast<std::size_t>(availBytes.QuadPart);
			}

		#else

			#if TOOLKIT_PLATFORM_BYTE == 32 || TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

				struct statfs st{ };

				if (::statfs(disk, &st) == -1)
				{
					return false;
				}

			#else

				struct statfs64 st{ };

				if (::statfs64(disk, &st) == -1)
				{
					return false;
				}

			#endif

			if (total)
			{
				*total = static_cast<std::size_t>(st.f_blocks) * static_cast<std::size_t>(st.f_bsize);
			}

			if (avail)
			{
				*avail = static_cast<std::size_t>(st.f_bfree) * static_cast<std::size_t>(st.f_bsize);
			}

		#endif

			return true;
		}

		/**
		 *
		 * 系统内存信息
		 *
		 * @param total 总体内存大小
		 * @param avail 空闲内存大小
		 *
		 * @return 是否获取成功
		 *
		 */
		static bool SystemMemoryInfo(std::size_t * total, std::size_t * avail)
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			MEMORYSTATUSEX memory{ 0 };

			memory.dwLength = sizeof(memory);

			if (::GlobalMemoryStatusEx(&memory) == FALSE)
			{
				return false;
			}

			if (total)
			{
				*total = static_cast<std::size_t>(memory.ullTotalPhys);
			}

			if (avail)
			{
				*avail = static_cast<std::size_t>(memory.ullAvailPhys);
			}

		#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

			#if defined(_SC_PAGESIZE)

				auto pagesize = ::sysconf(_SC_PAGESIZE);

			#elif defined(_SC_PAGE_SIZE)

				auto pagesize = ::sysconf(_SC_PAGE_SIZE);

			#endif

			if (pagesize == -1)
			{
				return false;
			}

			if (total)
			{
				auto pages = ::sysconf(_SC_PHYS_PAGES);

				if (pages == -1)
				{
					return false;
				}

				*total = static_cast<std::size_t>(pages) * static_cast<std::size_t>(pagesize);
			}

			if (avail)
			{
			#if TOOLKIT_PLATFORM_BYTE == 32

				vm_statistics_data_t info{ };

				mach_msg_type_number_t count = HOST_VM_INFO_COUNT;

				if (::host_statistics(::mach_host_self(), HOST_VM_INFO, reinterpret_cast<host_info_t>(&info), &count) != KERN_SUCCESS)
				{
					return false;
				}

			#else

				mach_msg_type_number_t count = HOST_VM_INFO64_COUNT;

				vm_statistics64_data_t info{ };

				if (::host_statistics64(::mach_host_self(), HOST_VM_INFO64, reinterpret_cast<host_info64_t>(&info), &count) != KERN_SUCCESS)
				{
					return false;
				}

			#endif

				*avail = static_cast<std::size_t>(info.free_count) * static_cast<std::size_t>(pagesize);
			}

		#else

			struct sysinfo si{ };

			if (::sysinfo(&si) == -1)
			{
				return false;
			}

			if (total)
			{
				*total = static_cast<std::size_t>(si.totalram) * static_cast<std::size_t>(si.mem_unit);
			}

			if (avail)
			{
				*avail = static_cast<std::size_t>(si.freeram) * static_cast<std::size_t>(si.mem_unit);
			}

		#endif

			return true;
		}


		////////////////////////////////////////////////////////////////////////////////////////////////////


		/**
		 *
		 * 是否是大端字节序
		 *
		 * @return 是否是大端字节序
		 *
		 */
		bool System::IsBigEndian()
		{
			static uint32_t value = 0x0001;

			return *(reinterpret_cast<uint8_t *>(&value)) == 0;
		}

		/**
		 *
		 * 是否是小端字节序
		 *
		 * @return 是否是小端字节序
		 *
		 */
		bool System::IsLittleEndian()
		{
			static uint32_t value = 0x0001;

			return *(reinterpret_cast<uint8_t *>(&value)) == 1;
		}

		/**
		 *
		 * 设置环境变量
		 *
		 * @param field 字段
		 * @param value 数值
		 *
		 * @return 环境变量
		 *
		 */
		bool System::SetEnvironment(const char * field, const char * value)
		{
			if (field == nullptr || value == nullptr)
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return ::SetEnvironmentVariable(field, value) == TRUE;

		#else

			return ::setenv(field, value, 1) == 0;

		#endif
		}

		/**
		 *
		 * 磁盘使用率
		 *
		 * @param disk 磁盘
		 *
		 * @return 磁盘使用率
		 *
		 */
		double System::DiskUsage(const char * disk)
		{
			if (disk == nullptr)
			{
				return 0.0;
			}

			std::size_t total{ 0 };
			std::size_t avail{ 0 };

			if (SystemDiskInfo(disk, &total, &avail))
			{
				return static_cast<double>(total - avail) / static_cast<double>(total);
			}

			return 0.0f;
		}

		/**
		 *
		 * 内存使用率
		 *
		 * @return 内存使用率
		 *
		 */
		double System::MemoryUsage()
		{
			std::size_t total{ 0 };
			std::size_t avail{ 0 };

			if (SystemMemoryInfo(&total, &avail))
			{
				return static_cast<double>(total - avail) / static_cast<double>(total);
			}

			return 0.0f;
		}

		/**
		 *
		 * 内存页大小
		 *
		 * @return 内存页大小
		 *
		 */
		uint32_t System::PageSize()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			SYSTEM_INFO info{ 0 };

			::GetSystemInfo(&info);

			return static_cast<uint32_t>(info.dwPageSize);

		#else

			#if defined(_SC_PAGESIZE)

				auto pagesize = ::sysconf(_SC_PAGESIZE);

			#elif defined(_SC_PAGE_SIZE)

				auto pagesize = ::sysconf(_SC_PAGE_SIZE);

			#endif

			return pagesize == -1 ? 0 : static_cast<uint32_t>(pagesize);

		#endif
		}

		/**
		 *
		 * 处理器个数
		 *
		 * @return 处理器个数
		 *
		 */
		uint32_t System::ProcessorCount()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			SYSTEM_INFO info{ 0 };

			::GetSystemInfo(&info);

			return static_cast<uint32_t>(info.dwNumberOfProcessors);

		#else

			return static_cast<uint32_t>(::sysconf(_SC_NPROCESSORS_CONF));

		#endif
		}

		/**
		 *
		 * 磁盘大小
		 *
		 * @param disk 磁盘
		 *
		 * @return 磁盘大小
		 *
		 */
		std::size_t System::DiskSize(const char * disk)
		{
			if (disk == nullptr)
			{
				return 0;
			}

			std::size_t total{ 0 };

			if (SystemDiskInfo(disk, &total, nullptr))
			{
				return total;
			}

			return 0;
		}

		/**
		 *
		 * 内存大小
		 *
		 * @return 内存大小
		 *
		 */
		std::size_t System::MemorySize()
		{
			std::size_t total{ 0 };

			if (SystemMemoryInfo(&total, nullptr))
			{
				return total;
			}

			return 0;
		}

		/**
		 *
		 * 磁盘已用大小
		 *
		 * @param disk 磁盘
		 *
		 * @return 磁盘已用大小
		 *
		 */
		std::size_t System::DiskUsedSize(const char * disk)
		{
			if (disk == nullptr)
			{
				return 0;
			}

			std::size_t total{ 0 };
			std::size_t avail{ 0 };

			if (SystemDiskInfo(disk, &total, &avail))
			{
				return total - avail;
			}

			return 0;
		}

		/**
		 *
		 * 磁盘空闲大小
		 *
		 * @param disk 磁盘
		 *
		 * @return 磁盘空闲大小
		 *
		 */
		std::size_t System::DiskFreeSize(const char * disk)
		{
			if (disk == nullptr)
			{
				return 0;
			}

			std::size_t avail{ 0 };

			if (SystemDiskInfo(disk, nullptr, &avail))
			{
				return avail;
			}

			return 0;
		}

		/**
		 *
		 * 内存已用大小
		 *
		 * @return 内存已用大小
		 *
		 */
		std::size_t System::MemoryUsedSize()
		{
			std::size_t total{ 0 };
			std::size_t avail{ 0 };

			if (SystemMemoryInfo(&total, &avail))
			{
				return total - avail;
			}

			return 0;
		}

		/**
		 *
		 * 内存空闲大小
		 *
		 * @return 内存空闲大小
		 *
		 */
		std::size_t System::MemoryFreeSize()
		{
			std::size_t avail{ 0 };

			if (SystemMemoryInfo(nullptr, &avail))
			{
				return avail;
			}

			return 0;
		}

		/**
		 *
		 * 用户名
		 *
		 * @return 用户名
		 *
		 */
		std::string System::UserName()
		{
			char content[TOOLKIT_NAME_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			DWORD size = TOOLKIT_NAME_MAX;

			if (::GetUserName(content, &size) == FALSE)
			{
				return std::string{ };
			}

		#else

			struct passwd pwd{ };
			struct passwd * result{ nullptr };

			::getpwuid_r(::getuid(), &pwd, content, TOOLKIT_NAME_MAX, &result);

			if (result == nullptr)
			{
				return std::string{ };
			}

		#endif

			return content;
		}

		/**
		 *
		 * 环境变量
		 *
		 * @param field 字段
		 *
		 * @return 环境变量
		 *
		 */
		std::string System::Environment(const char * field)
		{
			if (field == nullptr)
			{
				return std::string{ };
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			char result[256]{ 0 };

			if (::GetEnvironmentVariable(field, result, static_cast<DWORD>(sizeof(result))) == 0)
			{
				return std::string{ };
			}

			return result;

		#else

			char * result = ::getenv(field);

			return result ? result : std::string{ };

		#endif
		}

		/**
		 *
		 * 计算机名称
		 *
		 * @return 计算机名称
		 *
		 */
		std::string System::ComputerName()
		{
			char content[TOOLKIT_NAME_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			DWORD size = TOOLKIT_NAME_MAX;

			if (::GetComputerName(content, &size) == FALSE)
			{
				return std::string{ };
			}

		#else

			if (::gethostname(content, TOOLKIT_NAME_MAX))
			{
				return std::string{ };
			}

		#endif

			return content;
		}
	}
}
