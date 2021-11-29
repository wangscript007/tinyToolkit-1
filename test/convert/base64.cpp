/**
 *
 *  作者: hm
 *
 *  说明: base64
 *
 */


#include "base64.h"


TOOLKIT_TEST_CASE(Base64, Encode_Char)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(src.c_str()), dst);
}


TOOLKIT_TEST_CASE(Base64, Encode_UChar)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
}


TOOLKIT_TEST_CASE(Base64, Encode_String)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(src), dst);
}


TOOLKIT_TEST_CASE(Base64, Encode_Char_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLw==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(src.c_str(), 22), dst);
}


TOOLKIT_TEST_CASE(Base64, Encode_UChar_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLw==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(reinterpret_cast<const uint8_t *>(src.c_str()), 22), dst);
}


TOOLKIT_TEST_CASE(Base64, Encode_String_Length)
{
	std::string src = "https://www.baidu.com/?p1=123&p2=uuid";
	std::string dst = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLw==";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Encode(src, 22), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_Char)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(src.c_str()), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_UChar)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(reinterpret_cast<const uint8_t *>(src.c_str())), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_String)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/?p1=123&p2=uuid";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(src), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_Char_Length)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(src.c_str(), 29), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_UChar_Length)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(reinterpret_cast<const uint8_t *>(src.c_str()), 29), dst);
}


TOOLKIT_TEST_CASE(Base64, Decode_String_Length)
{
	std::string src = "aHR0cHM6Ly93d3cuYmFpZHUuY29tLz9wMT0xMjMmcDI9dXVpZA==";
	std::string dst = "https://www.baidu.com/";

	TOOLKIT_EXPECT_STR_EQ(tinyToolkit::convert::Base64::Decode(src, 29), dst);
}
