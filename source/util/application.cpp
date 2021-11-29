/**
 *
 *  作者: hm
 *
 *  说明: 应用信息
 *
 */


#include "application.h"

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS
#
#  include <Windows.h>
#  include <Psapi.h>
#  include <TlHelp32.h>
#
#else
#
#  include <cstdio>
#  include <csignal>
#  include <cstdlib>
#
#  include <unistd.h>
#
#  if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE
#
#    include <pthread.h>
#
#    include <mach/task.h>
#    include <mach/mach_init.h>
#
#    include <mach-o/dyld.h>
#
#  else
#
#    include <sys/prctl.h>
#    include <sys/syscall.h>
#
#  endif
#
#endif

#include <memory>
#include <cstring>
#include <functional>


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 是否存在
		 *
		 * @param pid 序列号
		 *
		 * @return 是否存在
		 *
		 */
		bool Application::Exist(uint64_t pid)
		{
			if (pid <= 0)
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> snapshotHandle
			(
				::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0),

				[](HANDLE handle)
				{
					if (handle && handle != INVALID_HANDLE_VALUE)
					{
						::CloseHandle(handle);
					}
				}
			);

			if (snapshotHandle == nullptr || snapshotHandle.get() == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			PROCESSENTRY32 processEntry{ };

			processEntry.dwSize = sizeof(processEntry);

			if (::Process32First(snapshotHandle.get(), &processEntry) == FALSE)
			{
				return false;
			}

			do
			{
				if (processEntry.th32ProcessID == pid)
				{
					return true;
				}
			} while (::Process32Next(snapshotHandle.get(), &processEntry));

		#else

			if (::kill(static_cast<pid_t>(pid), 0) == 0)
			{
				return true;
			}

		#endif

			return false;
		}

		/**
		 *
		 * 是否存在
		 *
		 * @param name 名称
		 *
		 * @return 是否存在
		 *
		 */
		bool Application::Exist(const std::string & name)
		{
			if (name.empty())
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> snapshotHandle
			(
				::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0),

				[](HANDLE handle)
				{
					if (handle && handle != INVALID_HANDLE_VALUE)
					{
						::CloseHandle(handle);
					}
				}
			);

			if (snapshotHandle == nullptr || snapshotHandle.get() == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			PROCESSENTRY32 processEntry{ };

			processEntry.dwSize = sizeof(processEntry);

			if (::Process32First(snapshotHandle.get(), &processEntry) == FALSE)
			{
				return false;
			}

			do
			{
				if (::strcmp(processEntry.szExeFile, name.c_str()) == 0)
				{
					return true;
				}
			} while (::Process32Next(snapshotHandle.get(), &processEntry));

		#else

			std::string command{ };

			command += "ps -ef | grep -w ";
			command += name;
			command += " | grep -v grep | grep -v /";
			command += name;
			command += "/ | wc -l";

			std::unique_ptr<FILE, std::function<void(FILE *)>> handle
			(
				::popen(command.c_str(), "r"),

				[](FILE * file)
				{
					if (file)
					{
						::pclose(file);
					}
				}
			);

			if (handle == nullptr)
			{
				return false;
			}

			char buffer[128]{ 0 };

			if (::fgets(buffer, sizeof(buffer), handle.get()))
			{
				return ::strtol(buffer, nullptr, 10) >= 1;
			}

		#endif

			return false;
		}

		/**
		 *
		 * 设置线程名称
		 *
		 * @param name 名称
		 *
		 * @return 是否设置成功
		 *
		 */
		bool Application::SetThreadName(const std::string & name)
		{
			if (name.empty())
			{
				return false;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			struct THREAD_NAME_INFO
			{
				DWORD type;
				LPCSTR name;
				DWORD id;
				DWORD flag;
			};

			THREAD_NAME_INFO info{ 0x1000, name.c_str(), static_cast<DWORD>(-1), 0 };

			__try
			{
				::RaiseException(0x406D1388, 0, static_cast<DWORD>(sizeof(info) / sizeof(DWORD)), reinterpret_cast<ULONG_PTR *>(&info));
			}
			__except(EXCEPTION_CONTINUE_EXECUTION)
			{

			}

			return true;

		#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

			return ::pthread_setname_np(name.c_str()) == 0;

		#else

			return ::prctl(PR_SET_NAME, name.c_str()) == 0;

		#endif
		}

		/**
		 *
		 * 线程序列号
		 *
		 * @return 线程序列号
		 *
		 */
		uint64_t Application::ThreadID()
		{
			static thread_local uint64_t tid = 0;

			if (tid == 0)
			{
			#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

				tid = static_cast<uint64_t>(::GetCurrentThreadId());

			#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

				::pthread_threadid_np(nullptr, &tid);

			#else

				tid = static_cast<uint64_t>(::syscall(SYS_gettid));

			#endif
			}

			return tid;
		}

		/**
		 *
		 * 进程序列号
		 *
		 * @return 进程序列号
		 *
		 */
		uint64_t Application::ProcessID()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return static_cast<uint64_t>(::GetCurrentProcessId());

		#else

			return static_cast<uint64_t>(::getpid());

		#endif
		}

		/**
		 *
		 * 占用内存
		 *
		 * @param pid 序列号
		 *
		 * @return 占用内存
		 *
		 */
		std::size_t Application::UsedMemory(uint64_t pid)
		{
			if (pid <= 0)
			{
				return 0;
			}

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> processHandle
			(
				::OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, static_cast<DWORD>(pid)),

				[](HANDLE handle)
				{
					if (handle && handle != INVALID_HANDLE_VALUE)
					{
						::CloseHandle(handle);
					}
				}
			);

			if (processHandle == nullptr || processHandle.get() == INVALID_HANDLE_VALUE)
			{
				return 0;
			}

			PROCESS_MEMORY_COUNTERS memory{ 0 };

			return ::GetProcessMemoryInfo(processHandle.get(), &memory, sizeof(memory)) == TRUE ? static_cast<std::size_t>(memory.WorkingSetSize) : 0;

		#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

			mach_port_name_t task = 0;

			if (::task_for_pid(::mach_task_self(), static_cast<int32_t>(pid), &task) != KERN_SUCCESS)
			{
				return 0;
			}

			mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;

			mach_task_basic_info_data_t info{ };

			return ::task_info(task, MACH_TASK_BASIC_INFO, reinterpret_cast<task_info_t>(&info), &count) == KERN_SUCCESS ? static_cast<std::size_t>(info.resident_size) : 0;

		#else

			std::string path = "/proc/" + std::to_string(pid) + "/status";

			std::unique_ptr<FILE, std::function<void(FILE *)>> handle
			(
				::fopen(path.c_str(), "r"),

				[](FILE * file)
				{
					if (file)
					{
						::pclose(file);
					}
				}
			);

			if (handle == nullptr)
			{
				return false;
			}

			char buffer[1024]{ 0 };

			while (true)
			{
				if (::fgets(buffer, sizeof(buffer), handle.get()) == nullptr)
				{
					break;
				}

				if (::strncmp(buffer, "VmRSS", 5) == 0)
				{
					return static_cast<std::size_t>(::strtol(buffer + 6, nullptr, 10)) * 1024;
				}
			}

			return 0;

		#endif
		}

		/**
		 *
		 * 名称
		 *
		 * @return 名称
		 *
		 */
		std::string Application::Name()
		{
			char content[TOOLKIT_PATH_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			auto size = ::GetModuleFileName(nullptr, content, TOOLKIT_PATH_MAX);

		#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

			uint32_t size = TOOLKIT_PATH_MAX;

			::_NSGetExecutablePath(content, &size);

		#else

			auto size = ::readlink("/proc/self/exe", content, TOOLKIT_PATH_MAX);

		#endif

			if (size < 0)
			{
				size = 0;
			}
			else if (size > TOOLKIT_PATH_MAX)
			{
				size = TOOLKIT_PATH_MAX;
			}

			content[size] = '\0';

			for (auto i = size; i > 0; --i)
			{
				if (content[i] == TOOLKIT_PATH_SEP)
				{
					return content + i + 1;
				}
			}

			return content;
		}

		/**
		 *
		 * 路径
		 *
		 * @return 路径
		 *
		 */
		std::string Application::Path()
		{
			char content[TOOLKIT_PATH_MAX + 1]{ 0 };

		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			auto size = ::GetModuleFileName(nullptr, content, TOOLKIT_PATH_MAX);

		#elif TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

			uint32_t size = TOOLKIT_PATH_MAX;

			::_NSGetExecutablePath(content, &size);

		#else

			auto size = ::readlink("/proc/self/exe", content, TOOLKIT_PATH_MAX);

		#endif

			if (size < 0)
			{
				size = 0;
			}
			else if (size > TOOLKIT_PATH_MAX)
			{
				size = TOOLKIT_PATH_MAX;
			}

			content[size] = '\0';

			return content;
		}

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
		std::string Application::CompileTimeString(const char * date, const char * time)
		{
			std::string content{ };

			content.reserve(20);

			content += date[7];
			content += date[8];
			content += date[9];
			content += date[10];
			content += '-';

			content.append(date[2] == 'n' ? (date[1] == 'a' ? "01" : "06") :
						   date[2] == 'b' ? "02" :
						   date[2] == 'r' ? (date[1] == 'a' ? "03" : "04") :
						   date[2] == 'y' ? "05" :
						   date[2] == 'l' ? "07" :
						   date[2] == 'g' ? "08" :
						   date[2] == 'p' ? "09" :
						   date[2] == 't' ? "10" :
						   date[2] == 'v' ? "11" : "12", 2);

			content += '-';
			content += date[4] == ' ' ? '0' : date[4];
			content += date[5];
			content += ' ';

			content.append(time, 8);

			return content;
		}
	}
}
