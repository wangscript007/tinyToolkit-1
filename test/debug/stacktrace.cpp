/**
 *
 *  作者: hm
 *
 *  说明: 堆栈信息
 *
 */


#include "stacktrace.h"


TOOLKIT_TEST_CASE(Stacktrace, Content)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_MIPS

	TOOLKIT_EXPECT_EQ(tinyToolkit::debug::Stacktrace::Content().length(), static_cast<std::size_t>(0));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::debug::Stacktrace::Content(), "");

#else

	TOOLKIT_EXPECT_GE(tinyToolkit::debug::Stacktrace::Content().length(), static_cast<std::size_t>(1));

#endif
}
