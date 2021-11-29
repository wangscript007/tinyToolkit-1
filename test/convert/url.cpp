/**
 *
 *  作者: hm
 *
 *  说明: url
 *
 */


#include "url.h"


TOOLKIT_TEST_CASE(Url, Encode_Char)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(src.c_str()), dst);
}


TOOLKIT_TEST_CASE(Url, Encode_UChar)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
}


TOOLKIT_TEST_CASE(Url, Encode_String)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(src), dst);
}


TOOLKIT_TEST_CASE(Url, Encode_Char_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(src.c_str(), 22), dst);
}


TOOLKIT_TEST_CASE(Url, Encode_UChar_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(reinterpret_cast<const uint8_t *>(src.c_str()), 22), dst);
}


TOOLKIT_TEST_CASE(Url, Encode_String_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "https%3A%2F%2Fwww.baidu.com%2F";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Encode(src, 22), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_Char)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(src.c_str()), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_UChar)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_String)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(src), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_Char_Length)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(src.c_str(), 30), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_UChar_Length)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(reinterpret_cast<const uint8_t *>(src.c_str()), 30), dst);
}


TOOLKIT_TEST_CASE(Url, Decode_String_Length)
{
	std::string src = "https%3A%2F%2Fwww.baidu.com%2F%3Fp1%3D123%26p2%3Duuid";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Url::Decode(src, 30), dst);
}
