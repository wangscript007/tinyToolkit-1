/**
 *
 *  作者: hm
 *
 *  说明: 系统信息
 *
 */


#include "system.h"


TOOLKIT_TEST_CASE(System, IsBigEndian)
{
	if (tinyToolkit::util::System::IsBigEndian())
	{
		TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::IsBigEndian());
		TOOLKIT_EXPECT_FALSE(tinyToolkit::util::System::IsLittleEndian());
	}
	else
	{
		TOOLKIT_EXPECT_FALSE(tinyToolkit::util::System::IsBigEndian());
		TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::IsLittleEndian());
	}
}


TOOLKIT_TEST_CASE(System, IsLittleEndian)
{
	if (tinyToolkit::util::System::IsLittleEndian())
	{
		TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::IsLittleEndian());
		TOOLKIT_EXPECT_FALSE(tinyToolkit::util::System::IsBigEndian());
	}
	else
	{
		TOOLKIT_EXPECT_FALSE(tinyToolkit::util::System::IsLittleEndian());
		TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::IsBigEndian());
	}
}


TOOLKIT_TEST_CASE(System, SetEnvironment)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::SetEnvironment("TEST_UTIL", "SetEnvironment"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("TEST_UTIL"), "SetEnvironment");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::System::SetEnvironment("TEST_UTIL", "GetEnvironment"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("TEST_UTIL"), "GetEnvironment");
}


TOOLKIT_TEST_CASE(System, DiskUsage)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	auto usage = tinyToolkit::util::System::DiskUsage("C:");

#else

	auto usage = tinyToolkit::util::System::DiskUsage("/");

#endif

	TOOLKIT_EXPECT_GE(usage, 0.01);
	TOOLKIT_EXPECT_LE(usage, 1.00);
}


TOOLKIT_TEST_CASE(System, MemoryUsage)
{
	auto usage = tinyToolkit::util::System::MemoryUsage();

	TOOLKIT_EXPECT_GE(usage, 0.01);
	TOOLKIT_EXPECT_LE(usage, 1.00);
}


TOOLKIT_TEST_CASE(System, PageSize)
{
	auto pageSize = tinyToolkit::util::System::PageSize();
	auto memorySize = tinyToolkit::util::System::MemorySize();

	TOOLKIT_EXPECT_GE(pageSize, static_cast<uint32_t>(1024));
	TOOLKIT_EXPECT_LE(pageSize, memorySize);
}


TOOLKIT_TEST_CASE(System, ProcessorCount)
{
	auto processorCount = tinyToolkit::util::System::ProcessorCount();

	TOOLKIT_EXPECT_GE(processorCount, static_cast<uint32_t>(1));
}


TOOLKIT_TEST_CASE(System, DiskSize)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	auto size = tinyToolkit::util::System::DiskSize("C:");

#else

	auto size = tinyToolkit::util::System::DiskSize("/");

#endif

	TOOLKIT_EXPECT_GE(size, static_cast<std::size_t>(1024));
}


TOOLKIT_TEST_CASE(System, MemorySize)
{
	auto size = tinyToolkit::util::System::MemorySize();

	TOOLKIT_EXPECT_GE(size, static_cast<std::size_t>(1024));
}


TOOLKIT_TEST_CASE(System, DiskUsedSize)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	auto size = tinyToolkit::util::System::DiskSize("C:");
	auto used = tinyToolkit::util::System::DiskUsedSize("C:");

#else

	auto size = tinyToolkit::util::System::DiskSize("/");
	auto used = tinyToolkit::util::System::DiskUsedSize("/");

#endif

	TOOLKIT_EXPECT_GE(used, static_cast<std::size_t>(1));
	TOOLKIT_EXPECT_LE(used, size);
}


TOOLKIT_TEST_CASE(System, DiskFreeSize)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	auto size = tinyToolkit::util::System::DiskSize("C:");
	auto free = tinyToolkit::util::System::DiskFreeSize("C:");

#else

	auto size = tinyToolkit::util::System::DiskSize("/");
	auto free = tinyToolkit::util::System::DiskFreeSize("/");

#endif

	TOOLKIT_EXPECT_GE(free, static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_LE(free, size);
}


TOOLKIT_TEST_CASE(System, MemoryUsedSize)
{
	auto size = tinyToolkit::util::System::MemorySize();
	auto used = tinyToolkit::util::System::MemoryUsedSize();

	TOOLKIT_EXPECT_GE(used, static_cast<std::size_t>(1));
	TOOLKIT_EXPECT_LE(used, size);
}


TOOLKIT_TEST_CASE(System, MemoryFreeSize)
{
	auto size = tinyToolkit::util::System::MemorySize();
	auto free = tinyToolkit::util::System::MemoryFreeSize();

	TOOLKIT_EXPECT_GE(free, static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_LE(free, size);
}


TOOLKIT_TEST_CASE(System, UserName)
{
	TOOLKIT_EXPECT_GE(tinyToolkit::util::System::UserName().length(), static_cast<std::size_t>(1));

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("USERNAME"), tinyToolkit::util::System::UserName());

#endif
}


TOOLKIT_TEST_CASE(System, Environment)
{
#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("NUMBER_OF_PROCESSORS"), std::to_string(tinyToolkit::util::System::ProcessorCount()));

#else

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("PWD"), tinyToolkit::util::Filesystem::CurrentDirectory());

#endif
}


TOOLKIT_TEST_CASE(System, ComputerName)
{
	TOOLKIT_EXPECT_GE(tinyToolkit::util::System::ComputerName().length(), static_cast<std::size_t>(1));

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::System::Environment("COMPUTERNAME"), tinyToolkit::util::System::ComputerName());

#endif
}
