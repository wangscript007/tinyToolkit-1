#ifndef __DEBUG__DUMP__H__
#define __DEBUG__DUMP__H__


/**
 *
 *  作者: hm
 *
 *  说明: 核心转储
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"


namespace tinyToolkit
{
	namespace debug
	{
		class TOOLKIT_API Dump
		{
		public:
			/**
			 *
			 * 绑定
			 *
			 */
			static void Hook();

			/**
			 *
			 * 释放
			 *
			 */
			static void Release();
		};
	}
}


#endif // __DEBUG__DUMP__H__
