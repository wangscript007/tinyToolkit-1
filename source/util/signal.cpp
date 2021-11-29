/**
 *
 *  作者: hm
 *
 *  说明: 信号处理
 *
 */


#include "signal.h"


namespace tinyToolkit
{
	namespace util
	{
		/**
		 *
		 * 注册忽略信号动作
		 *
		 */
		void Signal::RegisterIgnore(void(* callback)(int32_t))
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			TOOLKIT_UNUSED(callback);

		#else

			RegisterAction(SIGHUP, callback);
			RegisterAction(SIGPIPE, callback);
			RegisterAction(SIGCHLD, callback);

		#endif
		}

		/**
		 *
		 * 注册异常信号动作
		 *
		 * @param callback 回调函数
		 *
		 */
		void Signal::RegisterException(void(* callback)(int32_t))
		{
			RegisterAction(SIGILL, callback);
			RegisterAction(SIGFPE, callback);
			RegisterAction(SIGABRT, callback);
			RegisterAction(SIGSEGV, callback);
		}

		/**
		 *
		 * 注册结束信号动作
		 *
		 * @param callback 回调函数
		 *
		 */
		void Signal::RegisterTerminate(void(* callback)(int32_t))
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			RegisterAction(SIGINT, callback);
			RegisterAction(SIGTERM, callback);
			RegisterAction(SIGBREAK, callback);

		#else

			RegisterAction(SIGINT, callback);
			RegisterAction(SIGQUIT, callback);
			RegisterAction(SIGTERM, callback);
			RegisterAction(SIGTSTP, callback);

		#endif
		}

		/**
		 *
		 * 注销忽略信号动作
		 *
		 */
		void Signal::UnregisterIgnore()
		{
		#if TOOLKIT_PLATFORM_TYPE != TOOLKIT_PLATFORM_WINDOWS

			UnregisterAction(SIGHUP);
			UnregisterAction(SIGPIPE);
			UnregisterAction(SIGCHLD);

		#endif
		}

		/**
		 *
		 * 注销异常信号动作
		 *
		 */
		void Signal::UnregisterException()
		{
			UnregisterAction(SIGILL);
			UnregisterAction(SIGFPE);
			UnregisterAction(SIGABRT);
			UnregisterAction(SIGSEGV);
		}

		/**
		 *
		 * 注销结束信号动作
		 *
		 */
		void Signal::UnregisterTerminate()
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			UnregisterAction(SIGINT);
			UnregisterAction(SIGTERM);
			UnregisterAction(SIGBREAK);

		#else

			UnregisterAction(SIGINT);
			UnregisterAction(SIGQUIT);
			UnregisterAction(SIGTERM);
			UnregisterAction(SIGTSTP);

		#endif
		}

		/**
		 *
		 * 向自身发送信号
		 *
		 * @param sig 信号
		 *
		 * @return 是否发送成功
		 *
		 */
		bool Signal::Raise(int32_t sig)
		{
			return std::raise(sig) == 0;
		}

		/**
		 *
		 * 注册信号动作
		 *
		 * @param sig 信号
		 * @param callback 回调函数
		 *
		 * @return 是否注册成功
		 *
		 */
		bool Signal::RegisterAction(int32_t sig, void(* callback)(int32_t))
		{
		#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

			return std::signal(sig, callback) == callback;

		#else

			struct sigaction action{ };

			action.sa_flags = SA_SIGINFO;
			action.sa_handler = callback;

			#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

				sigemptyset(&action.sa_mask);

			#else

				::sigemptyset(&action.sa_mask);

			#endif

			#ifdef SA_RESTART

				action.sa_flags |= SA_RESTART;

			#endif

			return ::sigaction(sig, &action, nullptr) == 0;

		#endif
		}

		/**
		 *
		 * 注销信号动作
		 *
		 * @param sig 信号
		 *
		 * @return 是否注销成功
		 *
		 */
		bool Signal::UnregisterAction(int32_t sig)
		{
			return RegisterAction(sig, SIG_DFL);
		}
	}
}
