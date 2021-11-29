/**
 *
 *  作者: hm
 *
 *  说明: 核心转储
 *
 */


#include "dump.h"

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS
#
#  include <ctime>
#  include <chrono>
#  include <memory>
#  include <string>
#  include <cstdint>
#  include <functional>
#
#  include <Windows.h>
#  include <DbgHelp.h>
#
#  pragma comment(lib, "DbgHelp.lib")
#
#endif


namespace tinyToolkit
{
	namespace debug
	{
	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		/**
		 *
		 * 异常过滤器
		 *
		 */
		static LPTOP_LEVEL_EXCEPTION_FILTER sExceptionFilter = nullptr;

		/**
		 *
		 * 是否是需要的文件
		 *
		 * @param path 路径
		 *
		 * @return 是否是需要的文件
		 *
		 */
		static BOOL WINAPI IsNeedFile(const WCHAR * path)
		{
			if (path == nullptr)
			{
				return FALSE;
			}

			WCHAR file[TOOLKIT_NAME_MAX + 1]{ };

			::_wsplitpath_s(path, nullptr, 0, nullptr, 0, file, TOOLKIT_NAME_MAX, nullptr, 0);

			return ::_wcsicmp(file, L"ntdll") == 0 ? TRUE : FALSE;
		}

		/**
		 *
		 * 转储文件回调函数
		 *
		 * @param param 参数
		 * @param input 输入
		 * @param output 输出
		 *
		 * @return 是否转储成功
		 *
		 */
		static BOOL WINAPI DumpCallback(PVOID param, PMINIDUMP_CALLBACK_INPUT input, PMINIDUMP_CALLBACK_OUTPUT output)
		{
			TOOLKIT_UNUSED(param);

			if (input == nullptr || output == nullptr)
			{
				return FALSE;
			}

			switch (input->CallbackType)
			{
				case ModuleCallback:
				{
					if (output->ModuleWriteFlags & ModuleWriteDataSeg)
					{
						if (!IsNeedFile(input->Module.FullPath))
						{
							output->ModuleWriteFlags &= (~ModuleWriteDataSeg);
						}
					}
				}

				case ThreadCallback:
				case ThreadExCallback:
				case IncludeModuleCallback:
				case IncludeThreadCallback:
				{
					return TRUE;
				}

				default:
				{
					break;
				}
			}

			return FALSE;
		}

		/**
		 *
		 * 转储时间
		 *
		 * @return 转储时间
		 *
		 */
		static std::string WINAPI DumpTime()
		{
			std::tm now{ };

			int64_t timestamp = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count() + (8 * 3600);

			::gmtime_s(&now, &timestamp);

			std::string content{ };

			content.reserve(20);

			content += std::to_string(now.tm_year + 1900);
			content += '_';
			if (now.tm_mon < 9)
			{
				content += '0';
			}
			content += std::to_string(now.tm_mon + 1);
			content += '_';
			if (now.tm_mday < 10)
			{
				content += '0';
			}
			content += std::to_string(now.tm_mday);
			content += '_';
			if (now.tm_hour < 10)
			{
				content += '0';
			}
			content += std::to_string(now.tm_hour);
			content += '_';
			if (now.tm_min < 10)
			{
				content += '0';
			}
			content += std::to_string(now.tm_min);
			content += '_';
			if (now.tm_sec < 10)
			{
				content += '0';
			}
			content += std::to_string(now.tm_sec);

			return content;
		}

		/**
		 *
		 * 转储文件
		 *
		 * @return 转储文件
		 *
		 */
		static std::string WINAPI DumpFile()
		{
			char content[TOOLKIT_PATH_MAX + 1]{ 0 };

			DWORD size = ::GetModuleFileName(nullptr, content, TOOLKIT_PATH_MAX);

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
		 * 创建最小转储文件
		 *
		 * @param exception 异常
		 *
		 */
		static void WINAPI CreateMiniDump(PEXCEPTION_POINTERS exception)
		{
			std::string file{ };

			file += DumpFile();
			file += ".";
			file += DumpTime();
			file += ".dmp";

			std::unique_ptr<typename std::remove_pointer<HANDLE>::type, std::function<void(HANDLE)>> fileHandle
			(
				::CreateFile(file.c_str(), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_WRITE, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr),

				[](HANDLE handle)
				{
					if (handle && (handle != INVALID_HANDLE_VALUE))
					{
						::CloseHandle(handle);
					}
				}
			);

			if (fileHandle == nullptr || fileHandle.get() == INVALID_HANDLE_VALUE)
			{
				return;
			}

			MINIDUMP_EXCEPTION_INFORMATION exceptionInformation{ };

			exceptionInformation.ThreadId = ::GetCurrentThreadId();
			exceptionInformation.ClientPointers = FALSE;
			exceptionInformation.ExceptionPointers = exception;

			MINIDUMP_CALLBACK_INFORMATION callbackInformation{ };

			callbackInformation.CallbackParam = nullptr;
			callbackInformation.CallbackRoutine = static_cast<MINIDUMP_CALLBACK_ROUTINE>(DumpCallback);

			::MiniDumpWriteDump
			(
				::GetCurrentProcess(),
				::GetCurrentProcessId(),
				fileHandle.get(),
				static_cast<MINIDUMP_TYPE>(MiniDumpWithFullMemory | MiniDumpWithHandleData | MiniDumpWithFullMemoryInfo | MiniDumpWithThreadInfo | MiniDumpWithFullAuxiliaryState | MiniDumpIgnoreInaccessibleMemory),
				&exceptionInformation,
				nullptr,
				&callbackInformation
			);
		}

		/**
		 *
		 * 异常处理
		 *
		 * @param exception 异常
		 *
		 * @return 异常处理结果
		 *
		 */
		static LONG WINAPI ExceptionHandler(PEXCEPTION_POINTERS exception)
		{
			CreateMiniDump(exception);

			return EXCEPTION_EXECUTE_HANDLER;
		}

	#endif


		////////////////////////////////////////////////////////////////////////////////////////////////////


		/**
		 *
		 * 绑定
		 *
		 */
		void Dump::Hook()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (sExceptionFilter == nullptr)
			{
				sExceptionFilter = ::SetUnhandledExceptionFilter(ExceptionHandler);
			}

		#endif
		}

		/**
		 *
		 * 释放
		 *
		 */
		void Dump::Release()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			if (sExceptionFilter)
			{
				::SetUnhandledExceptionFilter(sExceptionFilter);

				sExceptionFilter = nullptr;
			}

		#endif
		}
	}
}
