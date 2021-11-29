/**
 *
 *  作者: hm
 *
 *  说明: 文件处理
 *
 */


#include "filesystem.h"


TOOLKIT_TEST_CASE(Filesystem, Chdir)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Chdir(""));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Chdir(std::string{ }));

	auto dir = tinyToolkit::util::Filesystem::CurrentDirectory();

	auto root = dir.substr(0, dir.find(TOOLKIT_PATH_SEP) + 1);

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Chdir(".."));

	if (dir == root)
	{
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::CurrentDirectory(), dir);
	}
	else
	{
		TOOLKIT_EXPECT_STR_NE(tinyToolkit::util::Filesystem::CurrentDirectory(), dir);
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Chdir(dir));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::CurrentDirectory(), dir);
}


TOOLKIT_TEST_CASE(Filesystem, Exists)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists(""));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists(std::string{ }));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
}


TOOLKIT_TEST_CASE(Filesystem, Remove)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove(""));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove(std::string{ }));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
}


TOOLKIT_TEST_CASE(Filesystem, Rename)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("", "test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename(std::string{ }, "test_rename_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_write.txt", "test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Rename("test_write.txt", "test_rename_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_directory", "test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Rename("test_directory", "test_rename_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_directories/first/2", "test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Rename("test_directories/first/2", "test_directories/first/rename_2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_rename_write.txt", "test_rename_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_rename_write.txt", "test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_rename_directory", "test_rename_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_rename_directory", "test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_directories/first/rename_2", "test_directories/first/rename_2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Rename("test_directories/first/rename_2", "test_directories/first/2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_rename_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_rename_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories/first/rename_2"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_rename_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/2"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories/first/rename_2"));
}


TOOLKIT_TEST_CASE(Filesystem, ReadFile)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));

	std::vector<std::string> vec{ TOOLKIT_LINE_EOL, TOOLKIT_LINE_EOL, "this", TOOLKIT_LINE_EOL, "fuck", TOOLKIT_LINE_EOL, TOOLKIT_LINE_EOL, "tick", TOOLKIT_LINE_EOL, TOOLKIT_LINE_EOL };

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vec.begin(), vec.end()));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));

	{
		auto lines = tinyToolkit::util::Filesystem::ReadFile("test_write.txt", false);

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(3));

		TOOLKIT_EXPECT_EQ(lines[0].size(), static_cast<std::size_t>(4));
		TOOLKIT_EXPECT_EQ(lines[1].size(), static_cast<std::size_t>(4));
		TOOLKIT_EXPECT_EQ(lines[2].size(), static_cast<std::size_t>(4));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "this");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "fuck");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "tick");
	}

	{
		auto lines = tinyToolkit::util::Filesystem::ReadFile("test_write.txt", true);

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(8));

		TOOLKIT_EXPECT_EQ(lines[0].size(), static_cast<std::size_t>(0));
		TOOLKIT_EXPECT_EQ(lines[1].size(), static_cast<std::size_t>(0));
		TOOLKIT_EXPECT_EQ(lines[2].size(), static_cast<std::size_t>(4));
		TOOLKIT_EXPECT_EQ(lines[3].size(), static_cast<std::size_t>(4));
		TOOLKIT_EXPECT_EQ(lines[4].size(), static_cast<std::size_t>(0));
		TOOLKIT_EXPECT_EQ(lines[5].size(), static_cast<std::size_t>(4));
		TOOLKIT_EXPECT_EQ(lines[6].size(), static_cast<std::size_t>(0));
		TOOLKIT_EXPECT_EQ(lines[7].size(), static_cast<std::size_t>(0));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "this");
		TOOLKIT_EXPECT_STR_EQ(lines[3], "fuck");
		TOOLKIT_EXPECT_STR_EQ(lines[4], "");
		TOOLKIT_EXPECT_STR_EQ(lines[5], "tick");
		TOOLKIT_EXPECT_STR_EQ(lines[6], "");
		TOOLKIT_EXPECT_STR_EQ(lines[7], "");
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
}


TOOLKIT_TEST_CASE(Filesystem, Traverse)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a2.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b2.txt"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("."));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse(".", true));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directory"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directory", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directories"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directories", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, Traverse_Pred)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b2"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a2.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b2.txt"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, true));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directories", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::Traverse("test_directories", [](const std::string & path) -> bool
		{
			return path.find_first_of("ab") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, WriteFile_Content)
{
	float varFloat = 1.0f;
	double varDouble = 0.1;
	int8_t varInt8 = 1;
	uint8_t varUInt8 = 1;
	int16_t varInt16 = 1;
	uint16_t varUInt16 = 1;
	int32_t varInt32 = 1;
	uint32_t varUInt32 = 1;
	int64_t varInt64 = 1;
	uint64_t varUInt64 = 1;
	std::string varString = "fuck";

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varFloat));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varDouble));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varUInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varUInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varUInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varUInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", varString));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varFloat));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varDouble));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varUInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varUInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varUInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varUInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, varString));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varFloat));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varDouble));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt8));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt8));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt16));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt16));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt32));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt32));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt64));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt64));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varString));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varFloat, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(1));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varDouble));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(4));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt8, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(1));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt8));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(2));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt16, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(1));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt16));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(2));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt32, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(1));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt32));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(2));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varInt64, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(1));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varUInt64));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(2));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", varString, true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(4));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varFloat));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varDouble));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt8));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt16));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt32));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt64));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varString));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varFloat));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varDouble));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt8));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt8));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt16));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt16));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt32));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt32));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varInt64));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varUInt64));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", varString));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));
}


TOOLKIT_TEST_CASE(Filesystem, WriteFile_Container)
{
	std::vector<float> vecFloat{ 1.0f, 2.0f, 3.0f };
	std::vector<double> vecDouble{ 0.0, 0.1, 0.2 };
	std::vector<int8_t> vecInt8{ 1, 2, 3 };
	std::vector<uint8_t> vecUInt8{ 1, 2, 3 };
	std::vector<int16_t> vecInt16{ 1, 2, 3 };
	std::vector<uint16_t> vecUInt16{ 1, 2, 3 };
	std::vector<int32_t> vecInt32{ 1, 2, 3 };
	std::vector<uint32_t> vecUInt32{ 1, 2, 3 };
	std::vector<int64_t> vecInt64{ 1, 2, 3 };
	std::vector<uint64_t> vecUInt64{ 1, 2, 3 };
	std::vector<std::string> vecString{ "this", "is", "vec" };

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecFloat.begin(), vecFloat.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecInt8.begin(), vecInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecInt16.begin(), vecInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecInt32.begin(), vecInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecInt64.begin(), vecInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("", vecString.begin(), vecString.end()));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecFloat.begin(), vecFloat.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecInt8.begin(), vecInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecInt16.begin(), vecInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecInt32.begin(), vecInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecInt64.begin(), vecInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile(std::string{ }, vecString.begin(), vecString.end()));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecFloat.begin(), vecFloat.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt8.begin(), vecInt8.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt16.begin(), vecInt16.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt32.begin(), vecInt32.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt64.begin(), vecInt64.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecString.begin(), vecString.end()));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecFloat.begin(), vecFloat.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(3));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(10));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt8.begin(), vecInt8.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(3));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(6));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt16.begin(), vecInt16.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(3));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(6));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt32.begin(), vecInt32.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(3));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(6));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecInt64.begin(), vecInt64.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(3));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(6));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_write.txt", vecString.begin(), vecString.end(), true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_write.txt"), static_cast<std::size_t>(9));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecFloat.begin(), vecFloat.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt8.begin(), vecInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt16.begin(), vecInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt32.begin(), vecInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt64.begin(), vecInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecString.begin(), vecString.end()));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecFloat.begin(), vecFloat.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecDouble.begin(), vecDouble.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt8.begin(), vecInt8.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt8.begin(), vecUInt8.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt16.begin(), vecInt16.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt16.begin(), vecUInt16.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt32.begin(), vecInt32.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt32.begin(), vecUInt32.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecInt64.begin(), vecInt64.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecUInt64.begin(), vecUInt64.end()));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_write.txt", vecString.begin(), vecString.end()));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));
}


TOOLKIT_TEST_CASE(Filesystem, CreateFiles)
{
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::CreateFiles(""));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::CreateFiles(std::string{ }));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_write.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory/test_write.txt"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_write.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory/test_write.txt"));
}


TOOLKIT_TEST_CASE(Filesystem, IsDirectory)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/a/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/a/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("."));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory(".."));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("./"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("../"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::IsDirectory("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::IsDirectory("test_directory/a/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
}


TOOLKIT_TEST_CASE(Filesystem, TraverseFile)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a2.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b2.txt"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("."));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile(".", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directory"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directory", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directories"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directories", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, TraverseFile_Pred)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/root.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/test.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/a/a2.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b1.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directories/b/b2.txt"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directories", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseFile("test_directories", [](const std::string & path) -> bool
		{
			return path.find_first_of("ab") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2.txt") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null.txt") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1.txt") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2.txt") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, CreateDirectories)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directories/a/b"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, TraverseDirectory)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b2"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("."));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory(".", true));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directory"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directory", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directories"));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directories", true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, TraverseDirectory_Pred)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/root"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/test"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/a/a2"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b1"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directories/b/b2"));

	auto Container = [](const std::vector<std::string> & container)
	{
		return std::unordered_set<std::string>{ container.begin(), container.end() };
	};

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory(".", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, true));

		TOOLKIT_EXPECT_TRUE(result.find("test_directory") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories") != result.end());

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directory", [](const std::string & path) -> bool
		{
			return path.find("root") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory\\null") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directory/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directory/null") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directories", [](const std::string & path) -> bool
		{
			return path.find("test") != std::string::npos;
		}, false));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") == result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") == result.end());

	#endif
	}

	{
		auto result = Container(tinyToolkit::util::Filesystem::TraverseDirectory("test_directories", [](const std::string & path) -> bool
		{
			return path.find_first_of("ab") != std::string::npos;
		}, true));

	#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\a\\a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories\\b\\b2") != result.end());

	#else

		TOOLKIT_EXPECT_TRUE(result.find("test_directories/root") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/test") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/null") == result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/a/a2") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b1") != result.end());
		TOOLKIT_EXPECT_TRUE(result.find("test_directories/b/b2") != result.end());

	#endif
	}

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directories"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directories"));
}


TOOLKIT_TEST_CASE(Filesystem, FileSize)
{
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize(""), static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize(std::string{ }), static_cast<std::size_t>(0));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));

	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_file.txt"), static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_directory/test_file.txt"), static_cast<std::size_t>(0));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test_file.txt"));

	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_file.txt"), static_cast<std::size_t>(0));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_directory/test_file.txt"), static_cast<std::size_t>(0));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", "fuck this world"));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_file.txt"), static_cast<std::size_t>(15));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", ". hello world"));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_file.txt"), static_cast<std::size_t>(28));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", "new content", true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_file.txt"), static_cast<std::size_t>(11));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", "fuck this world"));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_directory/test_file.txt"), static_cast<std::size_t>(15));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", ". hello world"));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_directory/test_file.txt"), static_cast<std::size_t>(28));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", "new content", true));
	TOOLKIT_EXPECT_EQ(tinyToolkit::util::Filesystem::FileSize("test_directory/test_file.txt"), static_cast<std::size_t>(11));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
}


TOOLKIT_TEST_CASE(Filesystem, Dirname)
{
	auto current = tinyToolkit::util::Filesystem::CurrentDirectory();

	auto root = current.substr(0, current.find(TOOLKIT_PATH_SEP) + 1);

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("b"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("c"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("123.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/b"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/c"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/123.txt"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname(""), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname(std::string{ }), "");

	{
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("123.txt"), ".");

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("123.txt"), ".");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/123.txt"), "/");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("123.txt/"), "123.txt");

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("a/456.txt"), "a");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/a/456.txt"), "/a");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("a/456.txt/"), "a/456.txt");

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("c/a/789.txt"), "c/a");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/c/a/789.txt"), "/c/a");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("c/a/789.txt/"), "c/a/789.txt");
	}

	{
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("123.txt", true), current);
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/123.txt", true), root);
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("123.txt/", true), "");

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("a/456.txt", true), "");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/a/456.txt", true), "");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("a/456.txt/", true), "");

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("c/a/789.txt", true), "");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("/c/a/789.txt", true), "");
		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Dirname("c/a/789.txt/", true), "");
	}
}


TOOLKIT_TEST_CASE(Filesystem, Basename)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename(""), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename(std::string{ }), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("123.txt"), "123.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("/123.txt"), "123.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("123.txt/"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("a/456.txt"), "456.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("/a/456.txt"), "456.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("a/456.txt/"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("c/a/789.txt"), "789.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("/c/a/789.txt"), "789.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Basename("c/a/789.txt/"), "");
}


TOOLKIT_TEST_CASE(Filesystem, Canonical)
{
	auto current = tinyToolkit::util::Filesystem::CurrentDirectory();

	auto root = current.substr(0, current.find(TOOLKIT_PATH_SEP) + 1);
	auto parent = std::count(current.begin(), current.end(), TOOLKIT_PATH_SEP) == 1 ? root : current.substr(0, current.rfind(TOOLKIT_PATH_SEP));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("../test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("../test_directory"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical(""), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("."), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical(".."), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical(std::string{ }), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("./"), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../"), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/"), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/.."), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../"), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../test_directory/a/.."), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../test_directory/a/../"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("/../test_directory/a/../1.txt"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/a.txt"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/a.txt"), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("../test_directory/a"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/a/a.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("../test_directory/a/a.txt"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/a/a.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("../test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("../test_directory/a/a.txt"));

#if TOOLKIT_PLATFORM_TYPE == TOOLKIT_PLATFORM_WINDOWS

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/a.txt"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a" + TOOLKIT_PATH_SEP + "a.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/.."), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/../"), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/a.txt"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a" + TOOLKIT_PATH_SEP + "a.txt");

#else

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a"), (current == root ? root : current + TOOLKIT_PATH_SEP)  + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/"), (current == root ? root : current + TOOLKIT_PATH_SEP)  + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/a/a.txt"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a" + TOOLKIT_PATH_SEP + "a.txt");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/.."), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory/../"), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("../test_directory/a/a.txt"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory" + TOOLKIT_PATH_SEP + "a" + TOOLKIT_PATH_SEP + "a.txt");

#endif

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("../test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("../test_directory"));
}


TOOLKIT_TEST_CASE(Filesystem, FileContent)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent(""), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent(std::string{ }), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_file.txt"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_directory/test_file.txt"), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateFiles("test_directory/test_file.txt"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_file.txt"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_directory/test_file.txt"), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", "fuck this world"));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_file.txt"), "fuck this world");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", ". hello world"));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_file.txt"), "fuck this world. hello world");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_file.txt", "new content", true));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_file.txt"), "new content");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", "fuck this world"));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_directory/test_file.txt"), "fuck this world");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", ". hello world"));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_directory/test_file.txt"), "fuck this world. hello world");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::WriteFile("test_directory/test_file.txt", "new content", true));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::FileContent("test_directory/test_file.txt"), "new content");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_file.txt"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_file.txt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
}


TOOLKIT_TEST_CASE(Filesystem, ParentDirectory)
{
	auto current = tinyToolkit::util::Filesystem::CurrentDirectory();

	auto root = current.substr(0, current.find(TOOLKIT_PATH_SEP) + 1);
	auto parent = (std::count(current.begin(), current.end(), TOOLKIT_PATH_SEP) == 1) ? root : current.substr(0, current.rfind(TOOLKIT_PATH_SEP));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("/test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("../test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("../test_directory"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory(""), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("."), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("./"), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory(".."), tinyToolkit::util::Filesystem::ParentDirectory(parent));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../"), tinyToolkit::util::Filesystem::ParentDirectory(parent));
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory(std::string{ }), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/"), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/.."), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../"), root);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../test_directory/a/.."), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../test_directory/a/../"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("/../test_directory/a/../1.txt"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/a"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/a/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/a"), "");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/a/"), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("../test_directory/a"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory/a"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("../test_directory/a"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory"), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/"), current);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/a"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/a/"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/.."), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory/../"), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory"), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/"), parent);
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/a"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("../test_directory/a/"), (parent == root ? root : parent + TOOLKIT_PATH_SEP) + "test_directory");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("../test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("../test_directory"));
}


TOOLKIT_TEST_CASE(Filesystem, CurrentDirectory)
{
	auto current = tinyToolkit::util::Filesystem::CurrentDirectory();

	auto root = current.substr(0, current.find(TOOLKIT_PATH_SEP) + 1);
	auto parent = (std::count(current.begin(), current.end(), TOOLKIT_PATH_SEP) == 1) ? root : current.substr(0, current.rfind(TOOLKIT_PATH_SEP));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory"), "");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory"), "");

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::CreateDirectories("test_directory"));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Exists("test_directory"));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::Canonical("test_directory"), (current == root ? root : current + TOOLKIT_PATH_SEP) + "test_directory");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::ParentDirectory("test_directory"), current);

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Chdir(".."));

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::Filesystem::CurrentDirectory(), parent);

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Chdir(current));

	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::Filesystem::Remove("test_directory"));

	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::Filesystem::Exists("test_directory"));
}
