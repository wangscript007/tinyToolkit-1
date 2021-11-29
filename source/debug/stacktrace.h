#ifndef __DEBUG__STACKTRACE__H__
#define __DEBUG__STACKTRACE__H__


/**
 *
 *  作者: hm
 *
 *  说明: 堆栈信息
 *
 */


#include "../common/define.h"
#include "../common/symbol.h"
#include "../common/version.h"

#include <string>


namespace tinyToolkit
{
	namespace debug
	{
		class TOOLKIT_API Stacktrace
		{
		public:
			/**
			 *
			 * 堆栈内容
			 *
			 * @return 堆栈内容
			 *
			 */
			static std::string Content();
		};
	}
}


#endif // __DEBUG__STACKTRACE__H__
