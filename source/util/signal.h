#ifndef __UTIL__SIGNAL__H__
#define __UTIL__SIGNAL__H__


/**
 *
 *  作者: hm
 *
 *  说明: 信号处理
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <cstdint>
#include <csignal>


namespace tinyToolkit
{
	namespace util
	{
		class TOOLKIT_API Signal
		{
		public:
			/**
			 *
			 * 注册忽略信号动作
			 *
			 */
			static void RegisterIgnore(void(* callback)(int32_t) = SIG_IGN);

			/**
			 *
			 * 注册异常信号动作
			 *
			 * @param callback 回调函数
			 *
			 */
			static void RegisterException(void(* callback)(int32_t));

			/**
			 *
			 * 注册结束信号动作
			 *
			 * @param callback 回调函数
			 *
			 */
			static void RegisterTerminate(void(* callback)(int32_t));

			/**
			 *
			 * 注销忽略信号动作
			 *
			 */
			static void UnregisterIgnore();

			/**
			 *
			 * 注销异常信号动作
			 *
			 */
			static void UnregisterException();

			/**
			 *
			 * 注销结束信号动作
			 *
			 */
			static void UnregisterTerminate();

			/**
			 *
			 * 向自身发送信号
			 *
			 * @param sig 信号
			 *
			 * @return 是否发送成功
			 *
			 */
			static bool Raise(int32_t sig);

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
			static bool RegisterAction(int32_t sig, void(* callback)(int32_t));

			/**
			 *
			 * 注销信号动作
			 *
			 * @param sig 信号
			 *
			 * @return 是否注销成功
			 *
			 */
			static bool UnregisterAction(int32_t sig);
		};
	}
}


#endif // __UTIL__SIGNAL__H__
