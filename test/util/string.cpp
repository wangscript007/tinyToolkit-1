/**
 *
 *  作者: hm
 *
 *  说明: 字符串处理
 *
 */


#include "string.h"


TOOLKIT_TEST_CASE(String, JoinStream_Arg)
{
	std::stringstream stream{ };

	tinyToolkit::util::String::JoinStream(stream, "123");

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "123");

	tinyToolkit::util::String::JoinStream(stream, 456);

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "123456");

	tinyToolkit::util::String::JoinStream(stream, 7.0);

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "1234567");

	tinyToolkit::util::String::JoinStream(stream, 8.9);

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "12345678.9");
}


TOOLKIT_TEST_CASE(String, JoinStream_Args)
{
	std::stringstream stream{ };

	tinyToolkit::util::String::JoinStream(stream, "123");

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "123");

	tinyToolkit::util::String::JoinStream(stream, 456, 7.0);

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "1234567");

	tinyToolkit::util::String::JoinStream(stream, 8.9, 0x0d, 0x0a);

	TOOLKIT_EXPECT_STR_EQ(stream.str(), "12345678.91310");
}


TOOLKIT_TEST_CASE(String, Join)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Join("cut", 123, " - ", 0.2f), "cut123 - 0.2");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Join("123", 456, "789", 0.33), "1234567890.33");
}


TOOLKIT_TEST_CASE(String, Erase_Char)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", '4'), " \t 112233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", '3'), " \t 1122 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", 'B'), " 112233 aAcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", 'b'), " 112233 aABBcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", '\t'), " 112233  aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", ' '), "112233\taABBcC");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", '3', 8), " \t 11223 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", '3', 9), " \t 112233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", 'B', 11), " 112233 aABcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", 'B', 12), " 112233 aABBcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", '\t', 8), " 112233  aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", ' ', 9), " 112233 \taABBcC");
}


TOOLKIT_TEST_CASE(String, Erase_String)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", "21"), " \t 112233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", "12"), " \t 1233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", "Ab"), " 112233 aABBcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", "Bc"), " 112233 aABC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", " \t "), " 112233aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", "\t\t"), " 112233 \t aABBcC ");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", "12", 4), " \t 1233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" \t 112233 aABBcC ", "12", 5), " \t 112233 aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", "Bc", 11), " 112233 aABC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 aABBcC \t ", "Bc", 12), " 112233 aABBcC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", " \t ", 7), " 112233aABBcC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Erase(" 112233 \t aABBcC ", " \t ", 8), " 112233 \t aABBcC ");
}


TOOLKIT_TEST_CASE(String, Lower)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" \t 123 aBc "), " \t 123 abc ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" 123 aBc \t "), " 123 abc \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" 123 \t aBc "), " 123 \t abc ");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" \t 123 aBc ", 7), " \t 123 abc ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" 123 aBc \t ", 7), " 123 aBc \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Lower(" 123 \t aBc ", 7), " 123 \t abc ");
}


TOOLKIT_TEST_CASE(String, Upper)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" \t 123 aBc "), " \t 123 ABC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" 123 aBc \t "), " 123 ABC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" 123 \t aBc "), " 123 \t ABC ");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" \t 123 aBc ", 7), " \t 123 ABC ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" 123 aBc \t ", 7), " 123 aBC \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Upper(" 123 \t aBc ", 7), " 123 \t ABC ");
}


TOOLKIT_TEST_CASE(String, Split)
{
	{
		auto lines = tinyToolkit::util::String::Split("ttt  ---  ABC %%%  22222211111324343TTT   ", " ");

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(5));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "ttt");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "---");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "ABC");
		TOOLKIT_EXPECT_STR_EQ(lines[3], "%%%");
		TOOLKIT_EXPECT_STR_EQ(lines[4], "22222211111324343TTT");
	}

	{
		auto lines = tinyToolkit::util::String::Split("ttt  ---  ABC %%%  22222211111324343TTT   ", " ", true);

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(10));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "ttt");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "---");
		TOOLKIT_EXPECT_STR_EQ(lines[3], "");
		TOOLKIT_EXPECT_STR_EQ(lines[4], "ABC");
		TOOLKIT_EXPECT_STR_EQ(lines[5], "%%%");
		TOOLKIT_EXPECT_STR_EQ(lines[6], "");
		TOOLKIT_EXPECT_STR_EQ(lines[7], "22222211111324343TTT");
		TOOLKIT_EXPECT_STR_EQ(lines[8], "");
		TOOLKIT_EXPECT_STR_EQ(lines[9], "");
	}
}


TOOLKIT_TEST_CASE(String, Replace)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Replace("21122112211212122121", "12", "21"), "21212121212121212211");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Replace("12211221122121122112", "12", "21"), "21212121212211212121");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Replace("21122112211212122121", "12", "21", 10), "21122112212121212211");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Replace("12211221122121122112", "12", "21", 15), "12211221122121122121");
}


TOOLKIT_TEST_CASE(String, EndWith)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::String::EndWith("ttt --- ABC %%% 22222211111324343TTT", "TTT"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::String::EndWith("ttt --- ABC %%% 22222211111324343TTT", "ttt"));
}


TOOLKIT_TEST_CASE(String, StartWith)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::String::StartWith("ttt --- ABC %%% 22222211111324343TTT", "ttt"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::String::StartWith("ttt --- ABC %%% 22222211111324343TTT", "TTT"));
}


TOOLKIT_TEST_CASE(String, SplitLine)
{
	{
		auto lines = tinyToolkit::util::String::SplitLine("ttt\n\n---\r\n\r\nABC\n%%%\n22222211111324343TTT\r\n\n\r\n");

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(5));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "ttt");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "---");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "ABC");
		TOOLKIT_EXPECT_STR_EQ(lines[3], "%%%");
		TOOLKIT_EXPECT_STR_EQ(lines[4], "22222211111324343TTT");
	}

	{
		auto lines = tinyToolkit::util::String::SplitLine("ttt\n\n---\r\n\r\nABC\n%%%\n22222211111324343TTT\r\n\n\r\n", true);

		TOOLKIT_EXPECT_EQ(lines.size(), static_cast<std::size_t>(9));

		TOOLKIT_EXPECT_STR_EQ(lines[0], "ttt");
		TOOLKIT_EXPECT_STR_EQ(lines[1], "");
		TOOLKIT_EXPECT_STR_EQ(lines[2], "---");
		TOOLKIT_EXPECT_STR_EQ(lines[3], "");
		TOOLKIT_EXPECT_STR_EQ(lines[4], "ABC");
		TOOLKIT_EXPECT_STR_EQ(lines[5], "%%%");
		TOOLKIT_EXPECT_STR_EQ(lines[6], "22222211111324343TTT");
		TOOLKIT_EXPECT_STR_EQ(lines[7], "");
		TOOLKIT_EXPECT_STR_EQ(lines[8], "");
	}
}


TOOLKIT_TEST_CASE(String, ReplaceLoop)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReplaceLoop("21122112211212122121", "12", "21"), "22222222221111111111");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReplaceLoop("12211221122121122112", "12", "21"), "22222222221111111111");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReplaceLoop("21122112211212122121", "12", "21", 10), "21122112212222211111");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReplaceLoop("12211221122121122112", "12", "21", 15), "12211221122121122211");
}


TOOLKIT_TEST_CASE(String, EqualIgnoreCase)
{
	TOOLKIT_EXPECT_TRUE(tinyToolkit::util::String::EqualIgnoreCase("abc", "AbC"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::String::EqualIgnoreCase("abc1", "AbC"));
	TOOLKIT_EXPECT_FALSE(tinyToolkit::util::String::EqualIgnoreCase("abc", "AbC1"));
}


TOOLKIT_TEST_CASE(String, Trim)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Trim(" \t 123 aBc "), "123 aBc");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Trim(" 123 aBc \t "), "123 aBc");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::Trim(" 123 \t aBc "), "123 \t aBc");
}


TOOLKIT_TEST_CASE(String, TrimLeft)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimLeft(" \t 123 aBc "), "123 aBc ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimLeft(" 123 aBc \t "), "123 aBc \t ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimLeft(" 123 \t aBc "), "123 \t aBc ");
}


TOOLKIT_TEST_CASE(String, TrimRight)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimRight(" \t 123 aBc "), " \t 123 aBc");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimRight(" 123 aBc \t "), " 123 aBc");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::TrimRight(" 123 \t aBc "), " 123 \t aBc");
}


TOOLKIT_TEST_CASE(String, ReduceJson)
{
	{
		std::string src = R"({"key_1": "value_1", "key_2": "value_2"})";
		std::string dst = R"({"key_1":"value_1","key_2":"value_2"})";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReduceJson(src), dst);
	}

	{
		std::string src = R"({"key_1": "value_1", "key_2": "value_2"} [{1, 3])";
		std::string dst = R"({"key_1":"value_1","key_2":"value_2"}[{1,3])";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ReduceJson(src), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_Char)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "3132334162437E21402324255E262A2829";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src.c_str()), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "29282A265E25242340217E436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src.c_str(), true), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_UChar)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "3132334162437E21402324255E262A2829";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "29282A265E25242340217E436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(reinterpret_cast<const uint8_t *>(src.c_str()), true), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_String)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "3132334162437E21402324255E262A2829";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "29282A265E25242340217E436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_Char_Length)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "313233416243";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src.c_str(), 6, false), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src.c_str(), 6, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_UChar_Length)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "313233416243";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(reinterpret_cast<const uint8_t *>(src.c_str()), 6, false), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(reinterpret_cast<const uint8_t *>(src.c_str()), 6, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, ToHexString_String_Length)
{
	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "313233416243";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src, 6, false), dst);
	}

	{
		std::string src = "123AbC~!@#$%^&*()";
		std::string dst = "436241333231";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ToHexString(src, 6, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, BeautifyJson)
{
	{
		std::string src = R"({"key_1": "value_1", "key_2": "value_2"})";
		std::string dst = tinyToolkit::util::String::Join
		(
			"{",
			TOOLKIT_LINE_EOL,
			"\t",
			R"("key_1":"value_1",)",
			TOOLKIT_LINE_EOL,
			"\t",
			R"("key_2":"value_2")",
			TOOLKIT_LINE_EOL,
			"}"
		);

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::BeautifyJson(src), dst);
	}

	{
		std::string src = R"({"key_1": "value_1", "key_2": "value_2"} [{1, 3])";
		std::string dst = tinyToolkit::util::String::Join
		(
			"{",
			TOOLKIT_LINE_EOL,
			"\t",
			R"("key_1":"value_1",)",
			TOOLKIT_LINE_EOL,
			"\t",
			R"("key_2":"value_2")",
			TOOLKIT_LINE_EOL,
			"}"
			TOOLKIT_LINE_EOL,
			"[",
			TOOLKIT_LINE_EOL,
			"\t{",
			TOOLKIT_LINE_EOL,
			"\t\t1,",
			TOOLKIT_LINE_EOL,
			"\t\t3",
			TOOLKIT_LINE_EOL,
			"\t]"
		);

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::BeautifyJson(src), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_Char)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC~!@#$%^&*()";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src.c_str()), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = ")(*&^%$#@!~CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src.c_str(), true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_UChar)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC~!@#$%^&*()";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = ")(*&^%$#@!~CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(reinterpret_cast<const uint8_t *>(src.c_str()), true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_String)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC~!@#$%^&*()";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = ")(*&^%$#@!~CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_Char_Length)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src.c_str(), 12, false), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src.c_str(), 12, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_UChar_Length)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(reinterpret_cast<const uint8_t *>(src.c_str()), 12, false), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(reinterpret_cast<const uint8_t *>(src.c_str()), 12, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FromHexString_String_Length)
{
	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "123AbC";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src, 12, false), dst);
	}

	{
		std::string src = "3132334162437E21402324255E262A2829";
		std::string dst = "CbA321";

		TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FromHexString(src, 12, true), dst);
	}
}


TOOLKIT_TEST_CASE(String, FilterComments)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FilterComments("123  //6666"), "123  ");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FilterComments("123 /*66*/6"), "123 6");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::FilterComments("123  //6666\\//"), "123  ");
}


TOOLKIT_TEST_CASE(String, ThousandsFormat)
{
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123"), "123");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234"), "1,234");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456"), "123,456");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567"), "1,234,567");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(";123"), ";123");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(";1234"), ";1234");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(";123456"), ";123456");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(";1234567"), ";1234567");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(".123"), ".123");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(".1234"), ".1234");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(".123456"), ".123456");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat(".1234567"), ".1234567");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123."), "123.");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234."), "1,234.");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456."), "123,456.");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567."), "1,234,567.");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123;"), "123;");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234;"), "1234;");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456;"), "123456;");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567;"), "1234567;");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123.987"), "123.987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234.987"), "1,234.987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456.987"), "123,456.987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567.987"), "1,234,567.987");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123;987"), "123;987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234;987"), "1234;987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456;987"), "123456;987");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567;987"), "1234567;987");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123.987654"), "123.987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234.987654"), "1,234.987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456.987654"), "123,456.987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567.987654"), "1,234,567.987654");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123;987654"), "123;987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234;987654"), "1234;987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456;987654"), "123456;987654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567;987654"), "1234567;987654");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123.987.654"), "123.987.654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234.987.654"), "1234.987.654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456.987.654"), "123456.987.654");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567.987.654"), "1234567.987.654");

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123.987654.321"), "123.987654.321");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234.987654.321"), "1234.987654.321");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("123456.987654.321"), "123456.987654.321");
	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::util::String::ThousandsFormat("1234567.987654.321"), "1234567.987654.321");
}
