/**
 *
 *  作者: hm
 *
 *  说明: 信号处理
 *
 */


#include "signal.h"


TOOLKIT_TEST_CASE(Signal, RegisterIgnore)
{
	tinyToolkit::util::Signal::RegisterIgnore();

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS



#else

	tinyToolkit::util::Signal::Raise(SIGHUP);
	tinyToolkit::util::Signal::Raise(SIGPIPE);
	tinyToolkit::util::Signal::Raise(SIGCHLD);

#endif
}


TOOLKIT_TEST_CASE(Signal, RegisterException)
{
	static int32_t count{ 0 };

	tinyToolkit::util::Signal::RegisterException([](int32_t signalNo) { TOOLKIT_UNUSED(signalNo); ++count; });

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	tinyToolkit::util::Signal::Raise(SIGILL);
	tinyToolkit::util::Signal::Raise(SIGFPE);
	tinyToolkit::util::Signal::Raise(SIGABRT);
	tinyToolkit::util::Signal::Raise(SIGSEGV);

	TOOLKIT_EXPECT_EQ(count, 4);

#else

	tinyToolkit::util::Signal::Raise(SIGILL);
	tinyToolkit::util::Signal::Raise(SIGFPE);
	tinyToolkit::util::Signal::Raise(SIGABRT);
	tinyToolkit::util::Signal::Raise(SIGSEGV);

	TOOLKIT_EXPECT_EQ(count, 4);

#endif
}


TOOLKIT_TEST_CASE(Signal, RegisterTerminate)
{
	static int32_t count{ 0 };

	tinyToolkit::util::Signal::RegisterTerminate([](int32_t signalNo) { TOOLKIT_UNUSED(signalNo); ++count; });

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	tinyToolkit::util::Signal::Raise(SIGINT);
	tinyToolkit::util::Signal::Raise(SIGTERM);
	tinyToolkit::util::Signal::Raise(SIGBREAK);

	TOOLKIT_EXPECT_EQ(count, 3);

#else

	tinyToolkit::util::Signal::Raise(SIGINT);
	tinyToolkit::util::Signal::Raise(SIGQUIT); /// clion会捕获这个信号
	tinyToolkit::util::Signal::Raise(SIGTERM);
	tinyToolkit::util::Signal::Raise(SIGTSTP);

	TOOLKIT_EXPECT_EQ(count, 4);

#endif
}


TOOLKIT_TEST_CASE(Signal, UnregisterIgnore)
{
	tinyToolkit::util::Signal::UnregisterIgnore();
}


TOOLKIT_TEST_CASE(Signal, UnregisterException)
{
	tinyToolkit::util::Signal::UnregisterException();
}


TOOLKIT_TEST_CASE(Signal, UnregisterTerminate)
{
	tinyToolkit::util::Signal::UnregisterTerminate();
}


TOOLKIT_TEST_CASE(Signal, Raise)
{

}


TOOLKIT_TEST_CASE(Signal, RegisterAction)
{

}


TOOLKIT_TEST_CASE(Signal, UnregisterAction)
{

}
