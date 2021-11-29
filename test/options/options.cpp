/**
 *
 *  作者: hm
 *
 *  说明: 选项
 *
 */


#include "options.h"


TOOLKIT_TEST_CASE(Options, Verbose)
{
	tinyToolkit::options::Options options{ };

	TOOLKIT_EXPECT_STR_EQ(options.Verbose(), "");

	{
		std::string content = TOOLKIT_LINE_EOL
							  "group_1:"
							  TOOLKIT_LINE_EOL
							  "  -h, --help      help message"
							  TOOLKIT_LINE_EOL;

		auto group_1 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_1");

		group_1->AddDescription()
		("help", "h", "help message");

		options.AddDescriptionGroup(group_1);

		TOOLKIT_EXPECT_STR_EQ(options.Verbose(), content);
	}

	{
		std::string content = TOOLKIT_LINE_EOL
							  "group_1:"
							  TOOLKIT_LINE_EOL
							  "  -h, --help              help message"
							  TOOLKIT_LINE_EOL
							  TOOLKIT_LINE_EOL
							  "group_2:"
							  TOOLKIT_LINE_EOL
							  "  -t, --test   required   test message"
							  TOOLKIT_LINE_EOL
							  "  -f, --fuck   required   fuck message"
							  TOOLKIT_LINE_EOL;

		auto group_2 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_2");

		group_2->AddDescription()
		("test", "t", "test message", tinyToolkit::options::Value<int8_t>())
		("fuck", "f", "fuck message", tinyToolkit::options::Value<int32_t>());

		options.AddDescriptionGroup(group_2);

		TOOLKIT_EXPECT_STR_EQ(options.Verbose(), content);
	}

	{
		std::string content = TOOLKIT_LINE_EOL
							  "group_1:"
							  TOOLKIT_LINE_EOL
							  "    -h, --help                                help message"
							  TOOLKIT_LINE_EOL
							  TOOLKIT_LINE_EOL
							  "group_2:"
							  TOOLKIT_LINE_EOL
							  "    -t, --test   required                     test message"
							  TOOLKIT_LINE_EOL
							  "    -f, --fuck   required                     fuck message"
							  TOOLKIT_LINE_EOL
							  TOOLKIT_LINE_EOL
							  "group_3:"
							  TOOLKIT_LINE_EOL
							  "      -i, --id   required (default=123)       id message"
							  TOOLKIT_LINE_EOL
							  "  -l, --logger   required (default=console)   logger message"
							  TOOLKIT_LINE_EOL;

		auto group_3 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_3");

		group_3->AddDescription()
		("id", "i", "id message", tinyToolkit::options::Value<int64_t>(123))
		("logger", "l", "logger message", tinyToolkit::options::Value<std::string>("console"));

		options.AddDescriptionGroup(group_3);

		TOOLKIT_EXPECT_STR_EQ(options.Verbose(), content);
	}
}


TOOLKIT_TEST_CASE(Options, Parse)
{
	tinyToolkit::options::Options options{ };

	auto group_1 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_1");
	auto group_2 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_2");
	auto group_3 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_3");
	auto group_4 = std::make_shared<tinyToolkit::options::DescriptionGroup>("group_4");

	group_1->AddDescription()
	("help", "h", "help message");

	group_2->AddDescription()
	("float", "f", "float message", tinyToolkit::options::Value<float>())
	("double", "d", "double message", tinyToolkit::options::Value<double>());

	group_3->AddDescription()
	("int8_t", "i8", "int8_t message", tinyToolkit::options::Value<int8_t>(1))
	("uint8_t", "u8", "uint8_t message", tinyToolkit::options::Value<uint8_t>(10))
	("int16_t", "i16", "int16_t message", tinyToolkit::options::Value<int16_t>(100))
	("uint16_t", "u16", "uint16_t message", tinyToolkit::options::Value<uint16_t>(1000))
	("int32_t", "i32", "int32_t message", tinyToolkit::options::Value<int32_t>(10000))
	("uint32_t", "u32", "uint32_t message", tinyToolkit::options::Value<uint32_t>(100000))
	("int64_t", "i64", "int64_t message", tinyToolkit::options::Value<int64_t>(1000000))
	("uint64_t", "u64", "uint64_t message", tinyToolkit::options::Value<uint64_t>(10000000));

	group_4->AddDescription()
	("string", "s", "string message", tinyToolkit::options::Value<std::string>("config/CONFIG.json"));

	TOOLKIT_EXPECT_FALSE(options.Exits("s"));
	TOOLKIT_EXPECT_FALSE(options.Exits("i8"));
	TOOLKIT_EXPECT_FALSE(options.Exits("u8"));
	TOOLKIT_EXPECT_FALSE(options.Exits("i16"));
	TOOLKIT_EXPECT_FALSE(options.Exits("u16"));
	TOOLKIT_EXPECT_FALSE(options.Exits("i32"));
	TOOLKIT_EXPECT_FALSE(options.Exits("u32"));
	TOOLKIT_EXPECT_FALSE(options.Exits("i64"));
	TOOLKIT_EXPECT_FALSE(options.Exits("u64"));

	TOOLKIT_EXPECT_FALSE(options.Exits("string"));
	TOOLKIT_EXPECT_FALSE(options.Exits("int8_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("uint8_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("int16_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("uint16_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("int32_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("uint32_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("int64_t"));
	TOOLKIT_EXPECT_FALSE(options.Exits("uint64_t"));

	TOOLKIT_EXPECT_FALSE(options.Exits("f"));
	TOOLKIT_EXPECT_FALSE(options.Exits("d"));

	TOOLKIT_EXPECT_FALSE(options.Exits("help"));
	TOOLKIT_EXPECT_FALSE(options.Exits("float"));
	TOOLKIT_EXPECT_FALSE(options.Exits("double"));

	options.AddDescriptionGroup(group_1);
	options.AddDescriptionGroup(group_2);
	options.AddDescriptionGroup(group_3);
	options.AddDescriptionGroup(group_4);

	TOOLKIT_EXPECT_TRUE(options.Exits("s"));
	TOOLKIT_EXPECT_TRUE(options.Exits("i8"));
	TOOLKIT_EXPECT_TRUE(options.Exits("u8"));
	TOOLKIT_EXPECT_TRUE(options.Exits("i16"));
	TOOLKIT_EXPECT_TRUE(options.Exits("u16"));
	TOOLKIT_EXPECT_TRUE(options.Exits("i32"));
	TOOLKIT_EXPECT_TRUE(options.Exits("u32"));
	TOOLKIT_EXPECT_TRUE(options.Exits("i64"));
	TOOLKIT_EXPECT_TRUE(options.Exits("u64"));

	TOOLKIT_EXPECT_TRUE(options.Exits("string"));
	TOOLKIT_EXPECT_TRUE(options.Exits("int8_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("uint8_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("int16_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("uint16_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("int32_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("uint32_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("int64_t"));
	TOOLKIT_EXPECT_TRUE(options.Exits("uint64_t"));

	TOOLKIT_EXPECT_FALSE(options.Exits("f"));
	TOOLKIT_EXPECT_FALSE(options.Exits("d"));

	TOOLKIT_EXPECT_FALSE(options.Exits("help"));
	TOOLKIT_EXPECT_FALSE(options.Exits("float"));
	TOOLKIT_EXPECT_FALSE(options.Exits("double"));

	const char * argv[] =
	{
		"test_option",
		"--help",
		"-f=0.01",
		"-d=0.02"
	};

	options.Parse(static_cast<int32_t>(sizeof(argv) / sizeof(const char *)), argv);

	TOOLKIT_EXPECT_EQ(options.Get<float>("f"), 0.01f);
	TOOLKIT_EXPECT_EQ(options.Get<float>("float"), 0.01f);
	TOOLKIT_EXPECT_EQ(options.Get<double>("d"), 0.02);
	TOOLKIT_EXPECT_EQ(options.Get<double>("double"), 0.02);
	TOOLKIT_EXPECT_EQ(options.Get<int8_t>("i8"), static_cast<int8_t>(1));
	TOOLKIT_EXPECT_EQ(options.Get<int8_t>("int8_t"), static_cast<int8_t>(1));
	TOOLKIT_EXPECT_EQ(options.Get<uint8_t>("u8"), static_cast<uint8_t>(10));
	TOOLKIT_EXPECT_EQ(options.Get<uint8_t>("uint8_t"), static_cast<uint8_t>(10));
	TOOLKIT_EXPECT_EQ(options.Get<int16_t>("i16"), static_cast<int16_t>(100));
	TOOLKIT_EXPECT_EQ(options.Get<int16_t>("int16_t"), static_cast<int16_t>(100));
	TOOLKIT_EXPECT_EQ(options.Get<uint16_t>("u16"), static_cast<uint16_t>(1000));
	TOOLKIT_EXPECT_EQ(options.Get<uint16_t>("uint16_t"), static_cast<uint16_t>(1000));
	TOOLKIT_EXPECT_EQ(options.Get<int32_t>("i32"), static_cast<int32_t>(10000));
	TOOLKIT_EXPECT_EQ(options.Get<int32_t>("int32_t"), static_cast<int32_t>(10000));
	TOOLKIT_EXPECT_EQ(options.Get<uint32_t>("u32"), static_cast<uint32_t>(100000));
	TOOLKIT_EXPECT_EQ(options.Get<uint32_t>("uint32_t"), static_cast<uint32_t>(100000));
	TOOLKIT_EXPECT_EQ(options.Get<int64_t>("i64"), static_cast<int64_t>(1000000));
	TOOLKIT_EXPECT_EQ(options.Get<int64_t>("int64_t"), static_cast<int64_t>(1000000));
	TOOLKIT_EXPECT_EQ(options.Get<uint64_t>("u64"), static_cast<uint64_t>(10000000));
	TOOLKIT_EXPECT_EQ(options.Get<uint64_t>("uint64_t"), static_cast<uint64_t>(10000000));

	TOOLKIT_EXPECT_STR_EQ(options.Get<std::string>("s"), "config/CONFIG.json");
	TOOLKIT_EXPECT_STR_EQ(options.Get<std::string>("string"), "config/CONFIG.json");
}
