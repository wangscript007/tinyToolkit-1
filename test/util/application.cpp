/**
 *
 *  作者: hm
 *
 *  说明: 应用信息
 *
 */


#include "application.h"


TOOLKIT_TEST_CASE(Application, Exist_ID)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Application::Exist(tinyToolkit::util::Application::ProcessID()));
}


TOOLKIT_TEST_CASE(Application, Exist_Name)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Application::Exist(tinyToolkit::util::Application::Name()));
}


TOOLKIT_TEST_CASE(Application, SetThreadName)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Application::SetThreadName("test_thread"));
}


TOOLKIT_TEST_CASE(Application, ThreadID)
{
	TOOLKIT_EXPECT_GE(tinyToolkit::util::Application::ThreadID(), static_cast<uint64_t>(1));

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS || TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

	TOOLKIT_EXPECT_NE(tinyToolkit::util::Application::ThreadID(), tinyToolkit::util::Application::ProcessID());

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Application::Exist(tinyToolkit::util::Application::ThreadID()));

#else

	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Application::ThreadID(), tinyToolkit::util::Application::ProcessID());

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Application::Exist(tinyToolkit::util::Application::ThreadID()));

#endif
}


TOOLKIT_TEST_CASE(Application, ProcessID)
{
	TOOLKIT_EXPECT_GE(tinyToolkit::util::Application::ProcessID(), static_cast<uint64_t>(1));

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS || TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_APPLE

	TOOLKIT_EXPECT_NE(tinyToolkit::util::Application::ProcessID(), tinyToolkit::util::Application::ThreadID());

#else

	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Application::ProcessID(), tinyToolkit::util::Application::ThreadID());

#endif

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Application::Exist(tinyToolkit::util::Application::ProcessID()));
}


TOOLKIT_TEST_CASE(Application, UsedMemory)
{
	auto usedMemory = tinyToolkit::util::Application::UsedMemory(tinyToolkit::util::Application::ProcessID());
	auto systemMemory = tinyToolkit::util::System::MemorySize();

	TOOLKIT_EXPECT_GE(usedMemory, static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_LE(usedMemory, systemMemory);
}


TOOLKIT_TEST_CASE(Application, Name)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Application::Name(), "test_util.exe");

#else

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Application::Name(), "test_util");

#endif
}


TOOLKIT_TEST_CASE(Application, Path)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::String::EndWith(tinyToolkit::util::Application::Path(), "\\test_util.exe"));

#else

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::String::EndWith(tinyToolkit::util::Application::Path(), "/test_util"));

#endif
}


TOOLKIT_TEST_CASE(Application, CompileTimeString)
{
	auto compile = tinyToolkit::util::Time::FromTimeString(tinyToolkit::util::Application::CompileTimeString().c_str());

	TOOLKIT_EXPECT_GE(compile, static_cast<int64_t>(1));
}
